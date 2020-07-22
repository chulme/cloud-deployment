//Pipeline requires PuTTY to be installed, as well as the following environment variables to be set:
//	aws_key: file location to aws key (needs to be converted from .pem to ppk using PuTTYgen;
//									   chmod 400 to send;
//									   chmod +x to execute on AWS)
//	aws_dns: the public dns to access AWS EC2 instance

def getCommandOutput(cmd) {
       stdout = bat(returnStdout:true , script: cmd).trim()
       result = stdout.readLines().drop(1).join(" ")       
       return result
}

pipeline{   
    
    agent any
	
    stages{

    //    stage('Build and run source code'){
    //        steps{
    //            echo 'Building...'
    //            bat 'g++ --version'
    //            bat 'mingw32-make'
    //            bat 'output'
    //        }
    //    }

        stage('Build and run unit tests'){
            steps{
                dir('Unit Tests'){
                    echo 'Testing...'
                    bat 'mingw32-make'
                    bat 'output'

                }
            }
        }

		stage('Build docker image'){
			steps{
				script{				
					bat 'docker build -t increment .' 
					bat 'docker run --rm --name Increment_Example_Jenkins increment'
				}
			}
		}
		
		stage('Export build output'){
			steps{
				script{
					dir('build_output'){
						deleteDir()
					}
					def script = '''docker create increment''' //creates a container around the image, returns the containerID in the console.
					def containerID = getCommandOutput(script)
					bat "docker cp ${containerID}:/src build_output" //copies the contents of the src folder, which only contains the cpp .exe
																	 //due to cleaning of all other files during the Docker build stage.
					bat "docker rm ${containerID}"
				}
			}
		}
		
		stage('Send build output to AWS via SSH'){
			steps{
				script{
					bat "echo y | pscp -i ${aws_key} build_output/output ${aws_dns}:build_output"	//echo y | required in the event of a ssh confirmation				
				}
			}
		}
		
		stage('Send image tar to AWS via SSH'){
			steps{
				script{
						bat "docker save increment >increment.tar"
						bat "echo y | pscp -i ${aws_key} increment.tar ${aws_dns}:increment.tar"	//echo y | required in the event of a ssh confirmation				
				}
			}
		}
		
		stage('Send image to AWS through Docker Compose'){
			steps{
				script{
					def image_name = "${aws_public_ip}/chrishulme/increment"
					bat "docker tag increment ${image_name}"
					bat "docker push ${image_name}"
				}
			}
		}

        stage('Reporting unit test results'){
            steps{
                dir("Unit Tests"){
                    junit '*.xml'
                }
            }
        }
		
    }
}