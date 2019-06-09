public class CRC_Generator_KDJ_ver {
	// 입력된 데이터를 CRC 코드로 변환해주는 메소드
	public static CRC toCRC(int data, int polynomial) { // KHJ
		int shifted = data << (getBitSize(polynomial)-1);
		int remainder = modulo_2_remainder(data, polynomial);
		System.out.println(bin2String(remainder));
		
		CRC crc = new CRC();
		crc.value = shifted | remainder;
		crc.polynomial = polynomial;
		return crc;
	}
	
	// CRC 코드로부터 원 데이터를 찾는 메소드
	public static int fromCRC(CRC crc) { // KDJ
		if (hasError(crc))
			return 0;
		return crc.value >>> (getBitSize(crc.polynomial)-1);
	}
	
	// CRC 오류 검사를 하는 메소드
	public static boolean hasError(CRC crc) { // KHJ
		if (modulo_2_remainder(crc.value, crc.polynomial) == 0)
			return false;

		System.out.println(modulo_2_remainder(crc.value, crc.polynomial)); // DEBUG
		return true;
	}
	
	// 모듈로-2 연산의 나머지를 반환하는 메소드
	public static int modulo_2_remainder(int data, int polynomial) { // KDJ
		int data_bitlen = getBitSize(data);
		int poly_bitlen = getBitSize(polynomial);
		int pivot, pin;
		
		// Operate modulo-2.
		for (pivot = data_bitlen-1; pivot >= poly_bitlen-1; pivot--) {
			// pass if MSB equals 0
			if (getBit(data, pivot) == 0)
				continue;
			// do XOR
			for (pin = 0; pin < poly_bitlen; pin++) {
				// Bit Masking
				if (getBit(data, pivot-pin) != getBit(polynomial, poly_bitlen-1-pin))
					data |= (1 << pivot-pin); // 해당 비트를 1로 바꿈
				else
					data &= ~(1 << pivot-pin); // 해당 비트를 0으로 바꿈
			}
		}
		return data;
	}
	
	// 2진수에서의 길이 구하기
	public static int getBitSize(int x) {
		final int SIZE_OF_INT = 32;
		for (int i = SIZE_OF_INT-1; i >= 0; i--)
			if (getBit(x, i) == 1)
				return i+1;
		return 0;
	}
	
	// 특정 자릿수의 비트를 가져오는 메소드
	public static int getBit(int x, int index) {
		return (x >>> index) & 1;
	}

	// 입력된 정수를 2진수로 출력하는 메소드
	public static String bin2String(int x) {
		return bin2String(x, false, false);
	}
	
	public static String bin2String(int x, boolean spacing, boolean printZeros) {
		final int SIZE_OF_INT = 32;
		int length = SIZE_OF_INT-1;
		String binaryString = "";
		
		if (!printZeros)
			length = getBitSize(x)-1;
		
		for (int i = length; i >= 0; i--) {
			if (getBit(x, i) == 0)
				binaryString += "0";
			else
				binaryString += "1";
			if (spacing && i % 8 == 0)
				binaryString += " ";
		}
		return binaryString;
	}
	
	public static int parsePolynomial(String polyString) { // KOH
		// formated "3*x^3+x^2+1*x+3"
		int poly = 0;
		boolean hasCoeff, hasExp;
		int exp;
		
		// 다항식을 단항식들의 배열로 분리하여, 각 단항식을 해석
		String[] products = polyString.split("\\+");
		for (String prod : products) {
			// 계수가 있는지 검사
			hasCoeff = prod.contains("*");
			if (hasCoeff && Integer.parseInt(prod.split("\\*")[0]) % 2 == 0)
				continue; // 계수가 0이면 넘어감
			
			// 차수 알아내기
			hasExp = prod.contains("^");
			if (!hasExp) { // 차수가 생략 되었을 경우, x^0 혹은 x^1
				exp = prod.contains("x") ? 1 : 0;
			}
			else {
				exp = Integer.parseInt(prod.split("\\^")[1]);
			}
			// 차수에 해당하는 비트를 1로 바꿈.
			poly |= (1 << exp);
		}
		return poly;
	}
}
