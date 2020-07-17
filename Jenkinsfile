
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
				bat 'docker run -it --rm --name Increment_Example_Jenkins increment'
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