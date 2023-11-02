APPS := fib

.PHONY: world clean cleanApps cleanKernel
world: $(APPS) kernel
	@echo "Done building World"

clean: cleanApps cleanKernel

cleanApps: $(addsuffix .clean,$(APPS))
	
cleanKernel:
	rm -rf ./Kernel/build

kernel: 
	if [ ! -d "./Kernel/build" ]; then cmake -B ./Kernel/build ./Kernel; fi
	cmake --build ./Kernel/build

%: ./Applications/%
	make -C $< build

%.clean: ./Applications/%
	make -C $< clean

