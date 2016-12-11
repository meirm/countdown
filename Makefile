countdown:
	g++ countdown.cpp -o countdown

install: countdown
	cp countdown /usr/local/bin

clean:
	rm countdown

.PHONY: clean
