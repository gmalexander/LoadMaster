## YAUTF

YAUTF, Yet Another Unit Testing Framework, is a small, lightweight unit testing framework for C++. It aims to deliver a lightweight solution to the problem of standardizable and maintainable unit testing output.

Please note that as a GPL v3 library, `yautf` will require you to license your project as GPL v3 or a compatible license, if you plan on distributing it with your application.

## Loading

YAUTF is designed to be loaded in one of two ways:
- Statically compiled alongside your source
- Dynamically linked against (see `yautf.cc` for pre-defined types that are compatible with dynamic linking)

Either way, it's as simple as including `yautf.hh` into the file that contains your unit test. `yautf.cc` exists in order to provide template definitions for the compiler for a number of types, and isn't anything that needs to be worried about, unless you plan to add more predefined types to this file and compile it as a shared object.

An up-to-date shared object will be provided in the releases section of this repository.

## Using YAUTF

YAUTF contains three classes, `TestManager`, `Test`, and `TestResult`. Each class is designed to specifically depend on the implementation of the other, for ease of building and importing. In general usage, only `TestManager` and `Test` should be referenced in code outside of the `yautf` namespace.

Here is a typical usage of `yautf`:

```
yautf::TestManager<int>* mgmt = new yautf::TestManager<int>();
std::string testName = "My Test"
int expectedValue = 1;
int actualValue = myObject.DoStuff();
yautf::Test<int>* tst = new yautf::Test<int>(testName, expectedValue);
tst->SetActual(actualValue);
mgmt->LoadTest(tst);
mgmt->VerifyTests();
mgmt->DisplayAllResults();
delete mgmt;
```

To break this down in chunks, we observe the following:

```
yautf::TestManager<int>* mgmt = new yautf::TestManager<int>();
```

First, we instantiate a new `TestManager` object to hold all of our `Test` objects. This object is a template, and will require the passing of a `typename`. This `typename` is propagated down to the `Test` objects it holds, and the `TestResult` object at the very bottom of the hierarchy.

```
std::string testName = "My Test"
int expectedValue = 1;
```

Here, we're just setting some expected values to pass to the constructor of `Test`. `testName` signifies the name of the case being executed, and will be displayed as output. `expectedValue` signifies the expected value, and will also be displayed as output, but is also used in the comparison against the actual value.

```
int actualValue = myObject.DoStuff();
```

With this statement, we are calling a hypothetical object in your code, `myObject` and invoking the method we wish to test: `DoStuff()`. Please note that as of current writing, `yautf` does not manage the *execution* of your test cases, only *output* and *comparison*.

```
yautf::Test<int>* tst = new yautf::Test<int>(testName, expectedValue);
tst->SetActual(actualValue);
```

In these lines, we are creating a new conceptual test, as a `Test` object, and passing our desired case name and expected value. The following call to the `Test` class' `SetActual` sets the actual value (but does not yet compare it!)

```
mgmt->LoadTest(tst);
```

This particular line loads the `Test` object into the `TestManager` instance. Internally, `TestManager` uses a `std::vector<T>` of the type `T` you define during instantiation. Note that the type of the `Test` **must** match the type of the `TestManager`. The amount of tests a `TestManager` can hold is only limited by the same limiting factors as the `MAX_CAPACITY` of `std::vector<T>`.

```
mgmt->VerifyTests();
```

In this portion, `VerifyTests` is invoked to cycle through all `Test` objects held in the `Test`-containing `std::vector` of `TestManager`.

```
mgmt->DisplayAllResults();
```

This section of the code tells the `TestManager` instance to loop through all `Test` objects held within the `Test`-containing `std::vector` of `TestManager`. This produces output of the following form:

```
TEST RESULTS:

For test: My Test
RESULT: SUCCESS
Expected: 1
Actual: 1
```

This is designed to be uniform for all tests, to ensure maximum trawlability by metrics scripts and other methods of tracking test cases.

```
delete mgmt;
```

And finally, we delete the `TestManager` instance for good housekeeping.