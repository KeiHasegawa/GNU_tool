all:
	for dir in $(wildcard *) ; do \
		if [ -d $$dir ]; then \
			cd $$dir; \
			$(MAKE) $(MY_MAKEFLAGS) all $(ERROR_EXIT); \
			cd ..; \
		fi \
	done

clean:
	for dir in $(wildcard *) ; do \
		if [ -d $$dir ]; then \
			cd $$dir; \
			$(MAKE) $(MY_MAKEFLAGS) clean; \
			cd ..; \
		fi \
	done
	rm -f *.o *~
