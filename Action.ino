void Action(char input) {
  if (input == 'F') {
    forward();
  } else if (input == 'B') {
    backward();
  } else if (input == 'L') {
    leftTurn();
  } else if (input == 'R') {
    rightTurn();
  } else if (input == 'G') {
    forwardLeft();
  } else if (input == 'I') {
    forwardRight();
  } else if (input == 'H') {
    backLeft();
  } else if (input == 'J') {
    backRight();
  } else if (input == 'S') {
    stopMotors();
  } else {
    // Handle invalid input here
  }
}
