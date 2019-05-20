(defpackage :main
  (:use cl))
(in-package :main)

(defun solveMeFirst (x y)
    (+ x y))

(defun main()
  (progn
    (let ((a) (b))
      (setq a (read-line))
      (setq b (read-line))

      (write (solveMeFirst (parse-integer a) (parse-integer b)))
      )
    )
 )

