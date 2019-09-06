ft_printf:

Approach:
    A recursive descent parser to convert formatting strings into an
array of formatting specifiers, which are then reduced into a single
output string

Bonuses:
1: * for width/prec
2: ability to register custom conversion functions, and swap out the default
    conversion specifiers (see `ftprintf_register_cnv`)
3: partial linking -> only the functions listed in `srcs/exported.sym` are
    exported by the linker, all others are not