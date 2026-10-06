,>                      read char 1 into cell 0, move to cell 1
,                       read char 2 into cell 1
<< ++++ ++++            cell 2 used as ASCII offset (48)
[
    > ----- -----
    > ----- -----
    << -
]
>>                      cell 0 and 1 now hold numeric values
<                       move to cell 1
[                       multiply cell 0 by cell 1 into cell 2
    <
    [
        > +
        > +
        << -
    ]
    >>
    [
        << +
        >> -
    ]
    < -
]
> ++++ ++++             convert result in cell 2 back to ASCII
[
    < +++++ +
    > -
]
< .                     print resulting digit
