(defun read-list (&optional (coerce #'identity))
  (loop for line = (read-line *standard-input* nil)
        until (eq line nil)
        collect (funcall coerce line)
        )
  )

(defun write-list (list)
  (loop for item in list
        do (prin1 item)
        do (terpri)
  )
  )

(defun my-abs (list)
  (mapcar #'abs list)
  )

(write-list (my-abs (read-list #'parse-integer)))
(terpri)
