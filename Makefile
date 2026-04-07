CXXFLAGS += -Wall -Wextra -Weffc++ -std=c++14 -MMD

UNIT_TESTS = pe-vector-tests
OBJS = main.o
DEPS = $(OBJS:%.o=%.d)

$(UNIT_TESTS): $(OBJS)
	$(CXX) -o $@ $^


run: $(UNIT_TESTS)
	./$<

test: run

clean:
	-@$(RM) $(UNIT_TESTS)
	-@$(RM) $(DEPS)
	-@$(RM) $(OBJS)

.PHONY: clean run test

-include main.d
