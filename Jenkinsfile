pipeline {
  agent {
    docker {
      image 'haliliceylan/vscode-bazel-dextool-environment:latest'
    }

  }
  stages {
    stage('check') {
      steps {
        sh 'whoami'
        sh '/opt/dextool_install/bin/dextool --help'
        sh 'cmake --help'
        sh 'uname -a'
      }
    }

    stage('build') {
      steps {
        sh '''cd simulink_example_cmake/bacteria-simulink/our_model_grt_rtw
./setup.sh'''
      }
    }

    stage('manuel test') {
      steps {
        sh '''cd simulink_example_cmake/bacteria-simulink/our_model_grt_rtw
make rl_test
./rl_test'''
      }
    }

  }
}