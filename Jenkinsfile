
pipeline{   
    
    agent any

    stages{

        stage('Build and run source code'){
            steps{
                echo 'Building...'
                bat 'g++ --version'
                bat 'mkdir obj'
                bat 'mingw32-make'
                bat './output'
            }
        }

        stage('Build and run unit tests'){
            steps{
                dir('Unit Tests'){
                    echo 'Testing...'
                    bat 'mkdir obj'
                    bat 'mingw32-make'
                    bat './output'

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