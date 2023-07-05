pipeline {
    agent any
    
    stages('Preparation') { // for display purposes
      steps
      {
        echo 'Pre-Build...'
        // Get some code from a GitHub repository
        //git 'https://github.com/jglick/simple-maven-project-with-tests.git'
        // Get the Maven tool.
        // ** NOTE: This 'M3' Maven tool must be configured
        // **       in the global configuration.
      }
        
    }
    stages('Perform Model-In-Loop Tests') {
      steps{
        // Run the maven build
        build 'Model_In_Loop_Stage'
        }
    }
    
    stages('Perform Auto CodeGenerattion') {
      steps{
        // Run the maven build
        build 'CodeGen'
        }
    }
    
    stages('Perform Software-In-Loop Tests') {
      steps{
        // Run the maven build
        build 'Software_In_Loop_Stage'
        }
    }
    stages('Results') {
      steps{
      echo 'Post-Build...'
      }
    }
}
