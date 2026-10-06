,>                     Read first digit character into cell 0, move to cell 1
,                      Read second digit character into cell 1
[                      Loop to add numeric value of cell 1 into cell 0
    < +
    > -
]
<                      Move back to cell 0
----- -----            Subtract 10
----- -----            Subtract 10
----- -----            Subtract 10
----- -----            Subtract 10
----                   Subtract 8 (Total subtracted: 48 = ASCII '0')
.                      Print result
