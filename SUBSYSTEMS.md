# SUBSYSTEMS

## Drive
- drivetrain
      - assuming tank for now...
```c
void tankDrive(int left, int right);
void arcadeDrive(int power, int rotation);
```

## Stakes
- gripper arm to pick up stakes
      - uhhh... servo? lol
```c
// Unsure on these functions ngl lol, like how long would they run for?
void close();
void open();
```

## Scoring Rings
- intake
      - Should it have a servo or something to drop it...?
      - Or do we even *need* an intake? The conveyor belt can just be the intake
- vertical conveyor for ring doohickeys (aka MOGO mech)
```c
void set(int power);
```

## Endgame Lift
- elevator w/ limit switches
```c
void set(int power); // with limit switches automatically stopping it if hit
bool isTouchingTop();
bool isTouchingBottom();
```