pipeline {
    agent any

    stages {

        stage('Install Dependencies') {
            steps {
                dir('build') {
                    sh 'conan install --build missing -s compiler.libcxx=libstdc++11 ..'
                }
            }
        }

        stage('Build') {
            steps {
                dir('build') {
                    sh 'cmake ..'
                    sh 'cmake --build .'
                }
            }
        }

        stage('Test') {
            steps {
                dir('build') {
                    sh 'ctest .'
                }
            }
        }

        stage('Bunding') {
            steps {
                dir('build') {
                    sh 'cpack .'
                }
            }
        }
    }

    post {

        // Save test report results
        always {
            junit 'build/*.xml'
        }

        success {
            archiveArtifacts artifacts: 'build/asl-*', fingerprint: true
        }
    }

}
