# Purpose
This repository is designed to bring together libraries from various projects in a logical manner. It's worth noting that individual project repositories may deviate from the standard 42 format; for instance, in this repository, get_next_line is linked to libft rather than duplicating functions across projects.
# Usage
1. just "make" will create a common 42lib.a out of all libraries.
2. alternatively you can specify to only include specific libraries, e.g.
   
   ```

   make ft_printf/libftprintf.a get_next_line/libgetnextline.a

   ```

   This approach will include dependent libraries, e.g. libft for ft_printf
