pipeline {
  agent {
    dockerfile {
      filename '.jenkins.Dockerfile'
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

    stage('test') {
      steps {
        sh '''cd simulink_example_cmake/bacteria-simulink/our_model_grt_rtw
cd build
make rl_test
./rl_test'''
        sh '''cd simulink_example_cmake/bacteria-simulink/our_model_grt_rtw
cd build
lcov -c -d . --output-file coverage.info
genhtml coverage.info --output-directory html

'''
        archiveArtifacts 'simulink_example_cmake/bacteria-simulink/our_model_grt_rtw/build/html/*'
        publishHTML([allowMissing: false, alwaysLinkToLastBuild: false, keepAll: true, reportDir: 'simulink_example_cmake/bacteria-simulink/our_model_grt_rtw/build/html/', reportFiles: 'index.html', reportName: 'Standart Test Report', reportTitles: ''])
      }
    }

    stage('mutation test') {
      steps {
        sh '''cd simulink_example_cmake/bacteria-simulink
/opt/dextool_install/bin/dextool mutate analyze
/opt/dextool_install/bin/dextool mutate test'''
        sh '''cd simulink_example_cmake/bacteria-simulink
/opt/dextool_install/bin/dextool mutate report'''
        archiveArtifacts 'simulink_example_cmake/bacteria-simulink/html/*'
        publishHTML([allowMissing: false, alwaysLinkToLastBuild: false, keepAll: true, reportDir: 'simulink_example_cmake/bacteria-simulink/html/', reportFiles: 'index.html', reportName: 'Mutation Test Report', reportTitles: ''])

      }
    }

  }
}
