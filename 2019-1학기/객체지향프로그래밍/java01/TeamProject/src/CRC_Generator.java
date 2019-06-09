class CRC { // CRC 자료형
	CRC() {
		this(0,0);
	}
	CRC(int val, int poly) {
		this.value = val;
		this.polynomial = poly;
	}
	
	int value; // CRC 코드
	int polynomial; // 사용된 CRC 발생 코드
}

public class CRC_Generator {
	// 입력된 데이터를 CRC 코드로 변환해주는 메소드
	public static CRC toCRC(int data, int polynomial) { // KHJ
		int change = (data << getBitSize(polynomial) - 1);
		int number = change | modulo_2_remainder(change, polynomial);
		  
		CRC crc = new CRC();
		crc.value = number;
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
		if (modulo_2_remainder(crc.value, crc.polynomial) != 0)
			return true;
		return false;
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
	public static int getBitSize(int x) { // KDJ
		final int SIZE_OF_INT = 32;
		for (int i = SIZE_OF_INT-1; i >= 0; i--)
			if (getBit(x, i) == 1)
				return i+1;
		return 0;
	}
	
	// 특정 자릿수의 비트를 가져오는 메소드
	public static int getBit(int x, int index) { // KDJ
		return (x >>> index) & 1;
	}

	// 입력된 정수를 2진수로 출력하는 메소드
	public static String bin2String(int x) { // KDJ
		return bin2String(x, false, false);
	}
	
	public static String bin2String(int x, boolean spacing, boolean printZeros) { // KDJ
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
	
	// 2진수 다항식을 문자열로 입력받아 정수로 해석해주는 메소드
	public static int parsePolynomial(String polyString) { // KOH
		int num, row, sum = 1, total = 0;
		  
		String result[] = polyString.split("(x\\^)|\\+");
		  
		for (int i = 0; i < result.length; i += 2)
		{
			sum = 0;
			num = Integer.parseInt(result[i]);
			row = Integer.parseInt(result[i + 1]);
			System.out.printf("num : %d, row : %d, ", num, row);
			if (num != 0)
			{
				sum = 1;
				for (int j = 0; j < row; j++)
				{
					sum = sum * 2;
				}
			}
			total += sum;
			System.out.printf("total : %d\n", total);
		}
		return total;
	}
}
