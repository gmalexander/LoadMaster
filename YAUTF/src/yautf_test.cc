#include "yautf.hh"

template <typename T>
void testInstantiationForType(T actual, T expected, std::string name)
{
   yautf::TestManager<T>* mgmt = new yautf::TestManager<T>();
   yautf::Test<T>* tst = new yautf::Test<T>(name, expected);
   tst->SetActual(actual);
   mgmt->LoadTest(tst);
   mgmt->VerifyTests();
   mgmt->DisplayAllResults();
   delete mgmt;
}

int main()
{
   testInstantiationForType<int>(1, 1, "Testing Integer Instantiation");
   testInstantiationForType<char>('a', 'a', "Testing Character Instantiation");
   testInstantiationForType<std::string>("a", "a", "Testing String Instantiation");
   testInstantiationForType<long>(1l, 1l, "Testing Long Instantiation");
   testInstantiationForType<bool>(true, true, "Testing Boolean Instantiation");
   testInstantiationForType<double>(1.0, 1.0, "Testing Double Instantiation");
   testInstantiationForType<float>(1.0f, 1.0f, "Testing Float Instantiation");
   return 0;
}
