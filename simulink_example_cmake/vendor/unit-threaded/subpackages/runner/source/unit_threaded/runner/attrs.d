/**
   UDAs for decorating tests.
 */
module unit_threaded.runner.attrs;

import unit_threaded.from;

enum UnitTest; //opt-in to registration
enum DontTest; //opt-out of registration
enum Serial; //run tests in the module in one thread / serially

alias SingleThreaded = Serial;

///Hide test. Not run by default but can be run.
struct HiddenTest {
    string reason;
}

/// The suite fails if the test passes.
struct ShouldFail {
    string reason;
}

/// The suite fails unless the test throws T
struct ShouldFailWith(T: Throwable) {
    alias Type = T;
    string reason;
}

/// Associate a name with a unittest block.
struct Name {
    string value;
}

/// Associates one or more tags with the test
struct Tags {
    this(string[] values...) { this.values = values;}
    this(string[] values) { this.values =  values; }
    this(string value)    { this.values = [value]; }
    string[] values;
}

/** Automatically assign @Tags for each parameterized test
 e.g.
---------------
@Values("foo", "bar") @AutoTags unittest { ... }
// there are now two unit tests, one for "foo" with tag "foo"
// and one for "bar" with tag "bar"
---------------
 */
enum AutoTags;

/** Attachs these types to the a parametrized unit test.
    The attached template function will be instantiated with
    each type listed, e.g.

    ----------------
    @Types!(int, byte) void testInit(T)() { T.init.shouldEqual(0); }
    ----------------

    These would mean two testInit test runs.

    Normally this would be a template but I don't know how to write
 *  the UDA code to filter a template out
 */
struct Types(T...) {
    alias types = T;
    enum length = T.length;
}


/**
 Used as a UDA for built-in unittests to enable value-parametrized tests.
 Example:
 -------
 @Values(1, 2, 3) unittest { assert(getValue!int % 2 == 0); }
 -------
 The example above results in unit_threaded running the unit tests 3 times,
 once for each value declared.

 See `getValue`.
 */
auto Values(T)(T[] values...) {
    return ValuesImpl!T(values.dup);
}

auto Values(R)(R values) if(from!"std.range.primitives".isInputRange!R) {
    import std.range.primitives: ElementType;
    import std.array: array;
    return ValuesImpl!(ElementType!R)(values.array);
}


struct ValuesImpl(T) {
    T[] values;
}

/**
 Retrieves the current test value of type T in a built-in unittest.
 See `Values`.
 */
T getValue(T, int index = 0)() {
    return ValueHolder!T.values[index];
}

package struct ValueHolder(T) {
    static T[10] values;
}


enum Setup;
enum Shutdown;

struct Flaky {
    /// the number of times to run the test
    enum defaultRetries = 10;
    int retries = defaultRetries;
}
