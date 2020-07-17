# Jenkins CI
A very straightforward pipeline used to learn the basics of Jenkins, CI/CD & the Catch unit-test framework.

## What is CI/CD?

CI stands for continuous integration, while CD stands for continuous delivery or deployment.

The technical goal of CI is to establish a consistent and automated way to build, package, and test applications. With consistency in the integration process in place, teams are more likely to commit code changes more frequently, which leads to better collaboration and software quality.

Continuous delivery picks up where continuous integration ends. CD automates the delivery of applications to selected infrastructure environments. Most teams work with multiple environments other than the production, such as development and testing environments, and CD ensures there is an automated way to push code changes to them.

For more, visit this [InfoWorld article](https://www.infoworld.com/article/3271126/what-is-cicd-continuous-integration-and-continuous-delivery-explained.html).

### What is Jenkins?
Jenkins is a free and open source automation server. It helps automate the parts of software development related to building, testing, and deploying, facilitating continuous integration and continuous delivery.

### What is Catch?
Catch (also known as Catch2) is a test framework for C++ - I quite like using it since it's very easy to setup (distributed through a single .hpp file), as well as being very easy to write tests with.

## Code Structure
* Jenkinsfile - the code for the Jenkins pipeline, which consists of 4 stages.
  1. Checkout - embedded with the pipeline on the server, and so not written in the Jenkinsfile.
  2. Build and run the source code
  3. Build and run unit tests
  4. Reportiing unit test results
* main - an arbitary main method used to validate the output of increment method.
* function_to_test - contains a simple method that takes an integer variable by reference and increments it.
* Unit Tests/catch_tests - holds various unit tests and a main method, which calls the Catch runner.
* Unit Tests/catch - the single header needed to use the Catch framework

## Output

![](https://i.imgur.com/VL8fwbB.png)
