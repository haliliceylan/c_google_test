for run all tests
"bazel test --test_output=all //:sample1_unittest"


"bazel build //simulink_example:our_model" //  simulink model build
remzi ke

"bazel test --test_output=ALL //simulink_example:our_model_unittest" // simulink model test example


adımlar // 
- Google test ile dextool mutate toolu kullanabilir mi (şuan hata veriyor)
- Bazelisk kullanan test.sh, build.sh oluşturabilir mi ?
- Mutate test config ayarlama
- Simulink modeli sadece belirli fonksiyonları model logicini içeriyor, sadecee bu fonksiyonların mutate işlemine tabi tutulması gerekiyor bunu yapmak için ne yapabilirz ?
    - ayrı bir dosyaya taşıyabilir
    - regex veya dextool mutate config ?
- Simulink model buildine bazeliske entegre etmemiz gerekiyor, şuanki örneklerden çok daha  karmaşık dosya çeşitleri var
- Simulink modeline bazelisk testi uygulanabilir mi ?

!!! duruma göre bazelisk ve googletest tamamen çıkartılabilir. !!!


Github CI  / JENKINS CI PART