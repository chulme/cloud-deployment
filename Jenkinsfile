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

def image_name = "tracker"
def container_name ="tracker_container"
def shared_workspace = "shared"
def image_loader_path="automation/image_loader.sh"

pipeline{   
    
    agent any
	
    stages{

		stage('Build docker image'){
			steps{
				script{				
					bat "docker build -t ${image_name} ." 
					bat "docker run --rm --name ${container_name} ${image_name}"
				}
			}
		}
		
		
		stage('Send image tar to AWS via SSH'){
			steps{
				script{
						bat "docker save ${image_name} >${image_name}.tar.gz"
						bat "echo y | pscp -i ${aws_key} ${image_name}.tar.gz ${aws_dns}:${shared_workspace}/${image_name}.tar.gz"	//echo y | required in the event of a ssh confirmation
				}
			}
		}
		
		stage("Load image to cloud server's Docker instance"){
			steps{
				script{
					bat "echo yes | ssh -i ${aws_dns} ${image_loader_path}"
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