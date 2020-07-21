
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
				bat 'docker build -t increment .'
				bat 'docker run --rm --name Increment_Example_Jenkins increment'
				
				def containerID = bat(script: 'docker create increment', returnStdout:true)
				echo "$containerID"
				bat 'docker cp $containerID:/src build_output'
				
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