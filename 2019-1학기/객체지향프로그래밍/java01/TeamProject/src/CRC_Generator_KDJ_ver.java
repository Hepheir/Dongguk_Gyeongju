public class CRC_Generator_KDJ_ver {
	// �Էµ� �����͸� CRC �ڵ�� ��ȯ���ִ� �޼ҵ�
	public static CRC toCRC(int data, int polynomial) { // KHJ
		int shifted = data << (getBitSize(polynomial)-1);
		int remainder = modulo_2_remainder(data, polynomial);
		System.out.println(bin2String(remainder));
		
		CRC crc = new CRC();
		crc.value = shifted | remainder;
		crc.polynomial = polynomial;
		return crc;
	}
	
	// CRC �ڵ�κ��� �� �����͸� ã�� �޼ҵ�
	public static int fromCRC(CRC crc) { // KDJ
		if (hasError(crc))
			return 0;
		return crc.value >>> (getBitSize(crc.polynomial)-1);
	}
	
	// CRC ���� �˻縦 �ϴ� �޼ҵ�
	public static boolean hasError(CRC crc) { // KHJ
		if (modulo_2_remainder(crc.value, crc.polynomial) == 0)
			return false;

		System.out.println(modulo_2_remainder(crc.value, crc.polynomial)); // DEBUG
		return true;
	}
	
	// ����-2 ������ �������� ��ȯ�ϴ� �޼ҵ�
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
					data |= (1 << pivot-pin); // �ش� ��Ʈ�� 1�� �ٲ�
				else
					data &= ~(1 << pivot-pin); // �ش� ��Ʈ�� 0���� �ٲ�
			}
		}
		return data;
	}
	
	// 2���������� ���� ���ϱ�
	public static int getBitSize(int x) {
		final int SIZE_OF_INT = 32;
		for (int i = SIZE_OF_INT-1; i >= 0; i--)
			if (getBit(x, i) == 1)
				return i+1;
		return 0;
	}
	
	// Ư�� �ڸ����� ��Ʈ�� �������� �޼ҵ�
	public static int getBit(int x, int index) {
		return (x >>> index) & 1;
	}

	// �Էµ� ������ 2������ ����ϴ� �޼ҵ�
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
		
		// ���׽��� ���׽ĵ��� �迭�� �и��Ͽ�, �� ���׽��� �ؼ�
		String[] products = polyString.split("\\+");
		for (String prod : products) {
			// ����� �ִ��� �˻�
			hasCoeff = prod.contains("*");
			if (hasCoeff && Integer.parseInt(prod.split("\\*")[0]) % 2 == 0)
				continue; // ����� 0�̸� �Ѿ
			
			// ���� �˾Ƴ���
			hasExp = prod.contains("^");
			if (!hasExp) { // ������ ���� �Ǿ��� ���, x^0 Ȥ�� x^1
				exp = prod.contains("x") ? 1 : 0;
			}
			else {
				exp = Integer.parseInt(prod.split("\\^")[1]);
			}
			// ������ �ش��ϴ� ��Ʈ�� 1�� �ٲ�.
			poly |= (1 << exp);
		}
		return poly;
	}
}
