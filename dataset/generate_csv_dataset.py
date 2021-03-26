import sys


def parse_args(argv):
    """
    Старайтесь писать комментарии к вашему коду,
    чтобы незнакомый с проектом человек смог разобраться ним.
    :param argv - входные параметры программы
    """
    print('Input arguments: {}'.format(sys.argv))


if __name__ == '__main__':
    parse_args(sys.argv)
    print('Generating CSV datasets ...')
