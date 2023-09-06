pipeline {
    agent any
    
    stages {
        stage('clone the repo') {
            steps {
                echo 'clone the repo'
                sh 'rm -rf petclinic-app'
                sh 'git clone https://github.com/Bohdan-Lesyk/petclinic-app.git'
            }
        }
        stage('push repo to remote host') {
            steps {
                sshagent(credentials: ['ssh-agent']) {
                    sh '''
                    ssh ubuntu@ec2-44-205-67-140.compute-1.amazonaws.com rm -rf /home/ubuntu/*
                    scp -r petclinic-app ubuntu@ec2-44-205-67-140.compute-1.amazonaws.com:~/
                    '''
                }
            }
        }
        stage('build docker container') {
            steps {
                sshagent(credentials: ['ssh-agent']) {
                    sh '''
                    ssh ubuntu@ec2-44-205-67-140.compute-1.amazonaws.com "cd petclinic-app && docker build -t petclinic-app . -f Dockerfile.cp"
                    '''
                }
            }
        }
        stage('run petclinic-app in docker container ') {
            steps {
                sshagent(credentials: ['ssh-agent']) {
                    sh '''
                    ssh ubuntu@ec2-44-205-67-140.compute-1.amazonaws.com docker run -d -p 8080:8080 petclinic-app
                    '''
                }
            }
        }
    }
}
