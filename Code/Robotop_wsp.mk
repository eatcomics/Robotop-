.PHONY: clean All

All:
	@echo ----------Building project:[ Robotop - Debug ]----------
	@"$(MAKE)" -f "Robotop.mk"
clean:
	@echo ----------Cleaning project:[ Robotop - Debug ]----------
	@"$(MAKE)" -f "Robotop.mk" clean
