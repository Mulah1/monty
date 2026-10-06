,>                      read char 1
,                       read char 2
<< ++++ ++++            subtract 48 ASCII offset from inputs
[
    > ----- -----
    > ----- -----
    << -
]
>>
<                       multiply cell 0 * cell 1 into cell 2
[
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
>                       cell 2 has result; decompose tens/ones
[
    > +++++ +++++       cell 3 = 10
    [
        < -
        > -
    ]
    > +                 increment tens in cell 4
    <<
]
<                       add ASCII offset 48 to tens (cell 4) and ones (cell 2)
++++ ++++
[
    < +++++ +
    >> +++++ +
    < -
]
<<                      print tens if greater than 0
[
    .
]
> .                     print ones digit
> +++++ +++++ .         print newline '\n' (ASCII 10)
