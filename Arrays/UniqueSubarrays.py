def get_connection():
	return "Connection"

def decorator(func):
	conn = get_connection()
	def func_wrapper(*args, **kwargs):
		print "Args[%s] Kwargs[%s]"%(args, kwargs)
		return func(conn, *args, **kwargs)

	return func_wrapper
@decorator
def connection(conn, db=None, details=None):
	print conn
	print "Inside Connection function"
	print "Db[%s], details[%s]"%(db, details)

def main():
	print "Inside Main Function"
	connection("master")

if __name__ == '__main__':
	main()