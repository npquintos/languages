#!/usr/bin/python26

import unittest

class Cxxx(object):

    @log.dlogger
    def __init__(self):
        pass

    def triple(self, arg):
        result = 3 * arg
        return result



################################################################################
# FUNCTIONS
################################################################################

@log.dlogger
def increase_by_2(arg):
    result = arg + 2
    return result

################################################################################
# TESTS
#       assertTrue(condition)
#       assertFalse(condition)
#       assertAlmostEqual(first, second, places=7, msg=None, delta=None)
#       assertListEqual(list1, list2, msg=None)
#       assertDictEqual(expected, actual, msg=None)
################################################################################

class TestCentre(unittest.TestCase):

    def test_increase_by_2(self): # function name should start with test_
        result_input = [
             # result, input
                [2,     0],
                [11,    9],
                [19,   17],
                [-1,   -3]
            ]
        self.test_for_truthfullness(result_input, increase_by_2)

    def test_class_Cxxx(self):
        myclass = Cxxx()
        result_input = [
             # result, input
                [0,     0],
                [27,    9],
                [-9,   -3]
            ]
        self.test_for_truthfullness(result_input, myclass.triple):

    def test_for_truthfullness(self, result_input, fx):
        for xpected_result, xinput in result_input:
            calc_result = fx(xinput)
            self.assertTrue(xpected_result == calc_result)


################################################################################
# MAIN
################################################################################

def main():
    # Comment out unit test below when done testing
    unittest.main()

    # real main() goes below
    # you don't have to comment it out while doing
    # unit Tests. It won't be run anyway
    print 'I am on real main now'


if __name__ == '__main__':
    main()
