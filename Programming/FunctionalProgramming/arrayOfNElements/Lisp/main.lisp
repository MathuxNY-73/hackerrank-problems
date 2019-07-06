(defun f (n)
  (if (<= n 0)
      nil
    (cons n (f (- n 1)))
    )
)

(let ((number (read)))
  (prin1 (f number))
)
