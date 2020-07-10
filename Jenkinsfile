def credentials = 'github-credentials'
def repo = 'https://github.com/chulme/jenkins-ci.git'

pipeline{   
    
    agent any

    stages{
        stage('Pull from Git'){
            steps{
                echo 'Pulling...'
                git branch: 'master', credentialsId: credentials, url: repo
            }
         }

        stage('Build and run source code'){
            steps{
                echo 'Building...'
                sh 'g++ --version'
                sh 'mkdir -p obj'
                sh 'make'
                sh './output'
            }
        }

        stage('Build and run unit tests'){
            steps{
                dir('Unit Tests'){
                    echo 'Testing...'
                    sh 'mkdir -p obj'
                    sh 'make'
                    sh './output'

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