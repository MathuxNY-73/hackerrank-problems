(defun read-list (&optional (coerce #'identity))
  (loop for line = (read-line *standard-input* nil)
        until (eq line nil)
        collect (funcall coerce line)
        )
  )

(defun length-rec (list &optional (res 0))
  (if (not list)
      res
      (length-rec (cdr list) (+ res 1))
      )
  )

(defun length-iter (list)
  (let ((res 0))
    (loop for x in list
          do (incf res))
    res
    )
  )


(prin1 (length-iter (read-list #'parse-integer)))
(terpri)
