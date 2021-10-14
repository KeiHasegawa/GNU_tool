(define_register_constraint "d" "D_REGS" "@internal")
(define_register_constraint "w" "SP_REGS" "@internal")
(define_register_constraint "x" "X_REGS" "@internal")
(define_register_constraint "y" "Y_REGS" "@internal")
(define_register_constraint "z" "Z_REGS" "@internal")
(define_register_constraint "D" "D_OR_X_REGS" "@internal")
(define_register_constraint "q" "Q_REGS" "@internal")
(define_register_constraint "u" "S_REGS" "@internal")
(define_register_constraint "A" "A_REGS" "@internal")
(define_register_constraint "B" "X_OR_Y_REGS" "@internal")
(define_register_constraint "h" "H_REGS" "@internal")
(define_memory_constraint "Q"
  "Matches an offsettable memory reference."
  (and (match_code "mem")
       (match_test "m68hc11_memory_constraint(op, 'Q')")))
(define_memory_constraint "R"
  "Matches an offsettable memory reference."
  (and (match_code "mem")
       (match_test "m68hc11_memory_constraint(op, 'R')")))
(define_memory_constraint "U"
  "Matches an offsettable memory reference."
  (and (match_code "mem")
       (match_test "m68hc11_memory_constraint(op, 'U')")))

(define_constraint "P"
  "Constant integer 1."
  (and (match_code "const_int")
       (match_test "m68hc11_int_constraint(ival, 'P')")))

(define_constraint "K"
  "Integer constant 2."
  (and (match_code "const_int")
       (match_test "m68hc11_int_constraint(ival, 'K')")))

(define_constraint "I"
  "Integer zero."
  (and (match_code "const_int")
       (match_test "m68hc11_int_constraint(ival, 'I')")))

(define_constraint "G"
  "Single-float zero."
  (and (match_code "const_double")
       (match_test "m68hc11_double_constraint(op)")))


(define_constraint "L"
  "Zero."
  (and (match_code "const_int")
       (match_test "m68hc11_int_constraint(ival, 'L')")))

(define_constraint "M"
  "Integer 1 or 2."
  (and (match_code "const_int")
       (match_test "m68hc11_int_constraint(ival, 'M')")))

(define_constraint "N"
  "Constant integer @minus{}1."
  (and (match_code "const_int")
       (match_test "m68hc11_int_constraint(ival, 'N')")))
