#include "pch.h"
#include "MsZip.h"

void CMsZip::OnBnClickedDecompressBtn()
{
	int file_size = 0;
	// ������ ������ ������ 'test.___' ���Ͽ��� ���� ������ �����ؼ� �����´�.
	// �̶� ������ ũ��� file_size�� ����ȴ�.
	char* p_data = ReadDataFromFile(L"test.___", &file_size);
	// ������ ������ ������ �ְ� �� ������ ���� ���!
	if (p_data != NULL) {
		DECOMPRESSOR_HANDLE decompressor;
		unsigned long decompressed_size = 0;
		// ������ ������ ��ü�� �����Ѵ�. ���� �˰����� MSZIP�� ����Ѵ�.
		if (CreateDecompressor(COMPRESS_ALGORITHM_MSZIP, NULL, &decompressor)) {
			// ������ ������ ������ �����Ϸ��� ������ ������ ũ�⸦ �˾ƾ� �ϱ� ������ 
			// �� ��° ���ڿ� NULL �׸��� �ټ� ��° ���ڿ� 0�� �ְ� ���� ���� �Լ��� �����ϸ�
			// �Լ��� �����ϸ鼭 ���� ��° ���ڿ� ������ �������� �� ũ�Ⱑ ����ȴ�.
			if (0 == Decompress(decompressor, p_data, file_size, NULL, 0, &decompressed_size)) {
				// ������ �����Ǿ��� �� ũ�⸦ ����� ��� ���!
				if (decompressed_size > 0) {
					// ������ ������ �����͸� �����ϱ� ���� �޸𸮸� �Ҵ��Ѵ�.
					char* p_decompress_data = new char[decompressed_size];
					// p_data�� �ִ� ������ ���������Ͽ� p_decompress_data�� �����Ѵ�.
					if (Decompress(decompressor, p_data, file_size,
						p_decompress_data, decompressed_size, &decompressed_size)) {
						// p_decompress_data�� ����� �����͸� ���Ͽ� �����Ѵ�.
						SaveDataToFile(L"unzip_test.bmp", p_decompress_data, decompressed_size);
					}
					// ������ ������ �����͸� �����ϱ� ���� �Ҵ��� �޸𸮸� �����Ѵ�.
					delete[] p_decompress_data;
				}
			}
			// ���� ������ ���� ���� ��ü�� �����Ѵ�.
			CloseCompressor(decompressor);
		}
		// ������ ������ �����ϱ� ���� �Ҵ��� �޸𸮸� �����Ѵ�.
		delete[] p_data;
	}
}
