# SUBSYSTEMS

## Drivetrain
- assuming tank for now...
```c
// If driver wants, add a parameter bool slowMode
// which would scale their input, perhaps with a sqrt() curve
void tankDrive(int left, int right);
void arcadeDrive(int power, int rotation);
// In the future, add autonomous-related functions here...
```

## Stakes / MOGO Mech
- Pneumatic clamp
```c
void close();
void open();
```

## Scoring Rings
- vertical conveyor for "ring doohickeys"
```c
void set(int power);
```

## Endgame Lift
- elevator w/ limit switches
```c
void set(int power); // with limit switches automatically stopping it if hit
bool isTouchingTop();
bool isTouchingBottom();
// Consider a task that semi-autonomously starts moving the lift until the limit switch is hit
//  OR when user input interrupts it (for manual override).
```