,>                      read char 1 into cell 0, move to cell 1
,                       read char 2 into cell 1
[                       loop cell 1 down to zero
    < +                 add to cell 0
    > -
]
<                       move to cell 0
----- -----             subtract 48 (ASCII offset for '0')
----- -----
----- -----
----- --- .             print resulting single-digit sum
