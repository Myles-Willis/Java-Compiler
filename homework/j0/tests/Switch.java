public class IfElseClass {
	public static void main(String argv[]) {

		switch (c) {
			case 1:
				doSomething();
				break;
			case 2:
				a = 33;
				break;
			case '3':
				doSomethingElse();
				break;
			default:
				doEverything();
				break;
		}

		switch (k) {
			case 1:
				doSomething();
				break;
			case 2:
				a = 33;
				break;
			case '3':
				doSomethingElse();
				break;
		}

		switch (argv.length) {
			case 1:
				doSomething();
				break;
			case 2:
				a = 33;
				break;
			case '3':
				doSomethingElse();
				break;
			default:
				doEverything();
		}

	}
}
