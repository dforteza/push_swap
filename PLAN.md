# push_swap: plan de proyecto

**Inicio:** mié 16-09-2026 · **Fecha objetivo:** mié 30-09-2026 (milestone) · **En pareja**
**Quién hace qué (decisión 20):** **A = dforteza** (entrada y datos: flags, parseo, errores, memoria, normalizar, desorden, `--simple`, `--medium`) · **B = compañera** (movimientos y algoritmos: operaciones, camino corto, casos pequeños, `--complex`, O(n)) · **Juntos**: base del repo, adaptativa, `--bench`, quicksort, README, defensa. Cada merge lo revisa el otro y el autor se lo explica.
**Alcance:** parte obligatoria con rendimiento **excelente** (100 → < 700 · 500 → < 5500). Bonus (`checker`) solo si sobra tiempo.
**Prioridad:** tiempo para entender y justificar la **complejidad** de cada algoritmo.
**Margen:** ritmo 15, quedan los paces 18, 22 y 24. Si el 28 no llegáis al excelente, se decide: entregar o mejorar.
**Referencia GNL:** se planificaron 10 días y el código estuvo en 2. Aquí hay más trabajo (4 algoritmos y en pareja), así que el plan es más holgado, pero si vais rápido el tiempo que sobre va a la **Fase 5**.

## Reparto por fases

| Fase | Peso | Días | Hito de salida |
|---|---|---|---|
| 1. Análisis | 5 % | mié 16 – jue 17 | Requisitos, errores y rendimiento anotados |
| 2. Diseño | 15 % | jue 17 – vie 18 | Estructura, flags, algoritmos y reparto decididos |
| 3. Base | 20 % | vie 18 – mar 22 | A: parseo + errores + normalizar + desorden + `--simple` OK · B: 11 operaciones + casos pequeños OK |
| 4. Algoritmos | 25 % | mié 23 – jue 24 | A: `--medium` OK · B: `--complex` y O(n) OK · Juntos: `--adaptive` |
| 5. Complejidad y rendimiento | 20 % | vie 25 – lun 28 | Excelente en 100 y 500, `--bench`, complejidad justificada |
| 6. Entrega | 15 % | mar 29 | README, Norma, 0 leaks, defensa preparada |
| Colchón | — | sáb 19, dom 20, sáb 26, dom 27 | Recuperar retrasos (o descansar) |
| **Objetivo** | — | **mié 30** | **Proyecto entregado** |

⚠️ La **defensa de GNL** (A) va antes del jue 24. Reservar hueco.

## Calendario

| Día | Juntos | A (dforteza) | B (compañera) | Estado |
|---|---|---|---|---|
| mié 16 | Lectura del subject | — | — | ✅ |
| jue 17 | Análisis + diseño | — | — | ✅ (terminado el vie 18) |
| vie 18 | Fin del diseño + repo, `.gitignore`, libft, Makefile, `.h` (structs, prototipos, reparto de ficheros) | Flags: diseño + esqueleto de `flags.c` | — | ✅ |
| sáb 19 | Colchón | Programar y probar `flags.c` → empezar parseo | (si hace falta) | ⬜ |
| dom 20 | Colchón | (si hace falta) | (si hace falta) | ⬜ |
| lun 21 | — | Flags + parseo + errores + construir `a` + liberar en error | Funciones internas + 11 operaciones con contadores, probadas una a una | ⬜ |
| mar 22 | Revisar y mergear lo del lun 21 | Normalizar + desorden + `--simple` | Camino corto + casos pequeños 2-5 | ⬜ |
| mié 23 | — | `--medium` (chunks) | `--complex` (radix) | ⬜ |
| jue 24 | `--adaptive` (+ n ≤ 5) | Defensa GNL + revisar lo de B | O(n) (comprobación + una vuelta) | ⬜ |
| vie 25 | `--bench` + script de medir | — | — | ⬜ |
| sáb 26 | Colchón | — | — | ⬜ |
| dom 27 | Colchón | — | — | ⬜ |
| lun 28 | Quicksort / optimizar hasta el excelente + análisis de complejidad | — | — | ⬜ |
| mar 29 | README, Norma, leaks, repaso de defensa | — | — | ⬜ |
| **mié 30** | **Objetivo** | — | — | ⬜ |

Estados: ⬜ pendiente · 🟨 en curso · ✅ hecho · 🟥 retrasado

---

## Checklist por fases

### 1. Análisis
- [x] Leer el subject completo (16-09)
- [x] Requisitos funcionales anotados (abajo, en "Requisitos")
- [x] Casos de error anotados
- [x] Objetivos de rendimiento anotados
- [x] Restricciones anotadas (funciones autorizadas, libft, sin globales, Norma)

### 2. Diseño
- [x] Estructura de las pilas (qué guarda cada elemento)
- [x] ¿Normalizar los números a índices 0..n-1? Por qué sí o por qué no
- [x] Regla de flags: posición, combinación con `--bench` y flags inválidos
- [x] Flujo del programa en pasos (de `argv` a la salida)
- [x] Cómo se imprime cada operación y cómo se cuentan para `--bench`
- [x] Cómo imprimir el desorden en `%` con dos decimales sin `%f`
- [x] Algoritmo O(n²) elegido y por qué
- [x] Algoritmo O(n√n) elegido y por qué
- [x] Algoritmo O(n log n) elegido y por qué
- [x] Algoritmo O(n) para desorden bajo (decisión 17)
- [x] Casos pequeños (2, 3, 4 y 5 números) (decisiones 16 y 18)
- [x] Umbrales de la adaptativa (0,2 / 0,5) y qué pasa con listas aleatorias (desorden ≈ 0,5) (decisión 19)
- [x] Memoria: qué se reserva, quién lo libera y qué pasa si falla un `malloc`
- [x] Reparto de ficheros → pasa a la Fase 3 (se hace al escribir el `.h`)
- [x] Reparto del trabajo con la compañera (los dos entienden todo) (decisión 20)
- [x] Flujo de git en pareja (ramas, quién mergea) (decisión 20)

### 3. Base
- [x] [Juntos] Repo git + `.gitignore`
- [x] [Juntos] `libft/` copiada con su Makefile
- [x] [Juntos] Makefile (skill `/makefile-42`): compila libft primero, sin relink
- [x] [Juntos] `.h` con structs y prototipos (nombres de las 11 operaciones y funciones internas pactados)
- [x] [Juntos] Reparto de ficheros (máx. 5 funciones por fichero, 25 líneas)
- [x] [Juntos] ¿PLAN.md va en el repo? → sí, `PLAN.md` y `tests/` dentro de git; quitarlos antes de vogsphere
- [ ] [A] Lectura de flags (decisión 6) → 🟨 rama `feat/flags`: esqueleto con descripciones, falta programar y probar
- [ ] [A] Parseo con `ft_split` + conversión + detección de errores (decisiones 3-5)
- [ ] [A] Construir la pila `a` (el primer argumento arriba)
- [ ] [A] Liberar todo y salir con `Error` (decisión 15), valgrind limpio también en error
- [ ] [A] Normalizar a índices (decisión 8)
- [ ] [A] Cálculo del índice de desorden (decisiones 2 y 11)
- [ ] [A] `--simple` (selección) da `OK` en el checker
- [ ] [B] Funciones internas que solo mueven (decisión 10)
- [ ] [B] Las 11 operaciones con contadores, probadas una a una
- [ ] [B] Camino corto (`ra`/`rra`), una sola función (decisión 18)
- [ ] [B] Casos pequeños 2, 3, 4 y 5 dan `OK` (decisiones 16 y 18)

### 4. Algoritmos
- [ ] [A] `--medium` (chunks) OK
- [ ] [B] `--complex` (radix) OK
- [ ] [B] O(n): comprobación + una vuelta, con plan B a chunks (decisión 17)
- [ ] [Juntos] `--adaptive` (y sin flag) elige según el desorden; n ≤ 5 → casos pequeños (decisión 19)

### 5. Complejidad y rendimiento
- [ ] [Juntos] `--bench` por stderr: desorden, estrategia, total y operaciones por tipo
- [ ] [Juntos] Script para medir: N ejecuciones aleatorias con 100 y 500 números (media y peor caso)
- [ ] [Juntos] Quicksort con mediana por índices (decisión 14) si radix no llega al excelente
- [ ] [Juntos] 100 números < 700 en el peor caso
- [ ] [Juntos] 500 números < 5500 en el peor caso
- [ ] [Juntos] Cada flag funciona con cualquier tamaño y desorden
- [ ] [Juntos] Complejidad (tiempo y espacio) de cada algoritmo en operaciones, explicada con vuestras palabras
- [ ] [Juntos] Umbrales justificados con mediciones

### 6. Entrega (todo juntos)
- [ ] Todos los casos de error → `Error\n` por stderr
- [ ] Sin argumentos y con un solo número → no imprime nada
- [ ] `valgrind`: 0 leaks, incluido el camino de error
- [ ] `norminette`: OK (libft incluida)
- [ ] README (skill `/readme-42`): logins de los dos, contribuciones, algoritmos, umbrales y complejidad, uso de IA
- [ ] Solo los ficheros exigidos en el repo
- [ ] Repaso de defensa: los dos explican cualquier parte y hacen una modificación pequeña en directo
- [ ] (Opcional) Bonus `checker`

---

## Requisitos

### Funcionales
- Entrada: flags **opcionales** (0, 1 o 2) + números enteros (positivos y negativos). Sin flag de estrategia → `--adaptive`.
- El **primer número** queda **arriba** de la pila `a`.
- Salida (stdout): la lista de operaciones **más corta posible**, una por línea (`\n` y nada más). Al final, `a` ordenada con el **menor arriba** y `b` vacía.

### Errores → `Error\n` por **stderr**
| Familia | Da `Error` | **No** da error |
|---|---|---|
| No es un número | `one`, `-`, `--5`, `5-`, `12a`, `""`, `"   "` | `+5`, `00042`, `0000000000042` |
| Fuera de `int` | `2147483648`, `-2147483649` | `-2147483648`, `2147483647` |
| Repetido (por valor) | `3 2 3`, `7 007`, `0 -0` | — |

Notas: convertir a `long` y comprobar el rango (con `int` el desbordamiento ya ha ocurrido); no detectar desbordamiento contando cifras. Flags inválidos: ver decisión 6.

### Rendimiento (números aleatorios, medido con el checker)
| Números | Corte | Bueno | **Excelente** (objetivo) |
|---|---|---|---|
| 100 | < 2000 | < 1500 | **< 700** |
| 500 | < 12000 | < 8000 | **< 5500** |

Se apunta al excelente; "bueno" es el plan B si el algoritmo no da para más.

### Restricciones
- Funciones: `read`, `write`, `malloc`, `free`, `exit` + `ft_printf` (o equivalente propio). libft permitida. `read` solo hace falta para el bonus `checker` (stdin, con GNL).
- Sin variables globales. Norma (todos los ficheros, también libft). `-Wall -Wextra -Werror`.
- Makefile: `NAME`, `all`, `clean`, `fclean`, `re`, sin relink.

## Decisiones de diseño

Provisionales (16-09):
1. Con menos de 2 números no se calcula nada y el programa sale sin imprimir. Así además se evita dividir entre cero en el desorden.
2. Desorden: contadores `int`, división en `double` (con división entera `1 / 6` da 0).
3. Duplicados por **valor** después de convertir (`7 007` y `0 -0` → `Error`). `+3` se acepta.
4. (17-09) Se aceptan números **sueltos y agrupados entre comillas**, también mezclados: `5 "4 3" 2`. Cada `argv[i]` se parte por espacios (`ft_split`) y hay que liberar el resultado. Motivo: `checker_linux "3 2 1"` lo acepta.
5. (17-09) Un argumento **sin números** (`""` o `"   "`) → `Error`. Con `ft_split`: `res[0] == NULL` significa "sin números", y `res == NULL` significa que falló un `malloc` (son dos casos distintos).

6. (17-09) **Flags**: solo **al principio** (antes del primer número), como mucho **2**: **una estrategia** y **un `--bench`**, en cualquier orden. Sin estrategia → `--adaptive` (`--bench` solo es válido).
   - `Error`: dos estrategias (`--simple --complex`), flag repetido (`--bench --bench`), flag inexistente (`--fast`), flag después de un número (`3 --bench 2`).
7. (17-09) **Pilas = lista enlazada simple** (solo `next`) con **nodo propio** (campo `int`), no el `t_list` de libft (`void *` → malloc por número y casts). Motivo: las operaciones solo cambian flechas (array movería todos los elementos); la doble no aporta nota (el tiempo no cuenta, solo las operaciones) y duplica los punteros a mantener. `rra` recorre hasta el penúltimo.
8. (17-09) **Normalizar a índices 0..n-1** (posición en la lista ordenada). El nodo guarda **valor** (duplicados, depurar) + **índice** (lo usan los algoritmos) + `next`. Motivo: chunks → `índice < 20` sin comparar con todos; radix → índices positivos y pocos bits (500 números → 9 bits = 9 pasadas, frente a 31 con los valores originales).
9. (17-09) **Flujo**: 1) leer flags → 2) parsear números, construir `a` y detectar errores → 3) < 2 números: salir sin imprimir → 4) normalizar a índices → 5) calcular desorden y elegir estrategia → 6) ejecutar algoritmo (imprime operaciones; si ya está ordenada no imprime nada) → 7) si `--bench`, estadísticas por stderr → 8) liberar y salir.
10. (17-09) **Struct principal** (sin globales), pasada por puntero a cada operación: pila `a`, pila `b`, estrategia, `bench` sí/no, **11 contadores**. Cada operación: mueve nodos + imprime su nombre + suma 1 a su contador. `rr`/`rrr`/`ss` cuentan **1** e imprimen su propio nombre → funciones internas que **solo mueven** (rotar, rotar inversa, swap, push) y las 11 operaciones públicas las usan.
11. (17-09) **Desorden en % sin `%f`**: `x = (int)(desorden × 10000 + 0.5)` (el +0.5 redondea; sin él 16.666 → 16.66) → parte entera `x / 100`, decimales `x % 100` → si decimales < 10, imprimir `"0"` delante (`16.05`, no `16.5`; `ft_printf` no tiene `%02d`).
12. (17-09) **`--simple` O(n²) = selección (sacar el mínimo)**: rotar `a` (`ra`/`rra`) hasta subir el menor → `pb` → repetir hasta vaciar `a` → `pa` hasta vaciar `b`. Motivo: es la que mejor se traduce a pilas (burbuja necesita `sa` en medio de la pila → muchas rotaciones; inserción necesita rotar `b` al hueco y deshacer). Complejidad: n búsquedas × hasta n rotaciones = O(n²).
13. (17-09) **`--medium` O(n√n) = chunks (bloques)**: selección mejorada. Bloques de ≈ √n índices (0..√n-1 = pequeños, etc.; son etiquetas, no pilas). **Ida:** si la cima de `a` es del bloque actual → `pb`, si no → `ra`; al completar el bloque, siguiente bloque → `b` queda por capas (pequeños abajo, grandes arriba, sin ordenar dentro). **Vuelta:** sacar el mayor de `b` (`rb`/`rrb` por el camino corto, o `sb` si es el segundo) → `pa`. Complejidad: n números × ≈ √n rotaciones. Ejemplo n = 9: 13 + 16 = 29 ops.
14. (17-09) **`--complex` O(n log n) = radix LSD binario sobre índices** (seguro, "bueno": ~1084 con 100 y ~6784 con 500). Pasada `i` (de 0 a bits de n-1): para cada uno de los n elementos, `(índice >> i) & 1` → 0: `pb`, 1: `ra`; luego `pa` hasta vaciar `b`. Funciona porque cada pasada es **estable** (respeta el orden previo entre los de igual bit). Complejidad: log n pasadas × ~n ops. Descartados: heap sort y árbol binario indexado (no se traducen a pilas); merge sort (demasiado enrevesado). **Mejora para el excelente (Fase 5): quicksort con pilas** usando como pivote la mediana exacta por índices (siempre parte en mitades → O(n log n) garantizado). Si no llega a tiempo, se entrega con radix.
15. (17-09) **Memoria**: 2 reservas. (1) **Nodos**: duran todo el programa, se liberan al final. (2) **Resultado de `ft_split`**: temporal, se libera al terminar de convertir cada `argv[i]`. **Camino de error** (número inválido o `malloc` fallido): una función que libera el split en curso + pilas `a` y `b` (vía struct principal) → `Error\n` por stderr → `exit`. `exit` no libera nada: valgrind 0 leaks también en error.
16. (17-09, parcial) **Ordenar 3** (índices relativos 0-1-2, máx. 2 ops, sin usar `b`): `0 1 2` → nada · `1 0 2` → `sa` · `2 0 1` → `ra` · `1 2 0` → `rra` · `0 2 1` → `rra sa` · `2 1 0` → `sa rra` (o `ra sa`). **Método para programar**: 1) llevar el mayor abajo (arriba → `ra`, en medio → `rra`, abajo → nada); 2) si los dos de arriba están al revés → `sa`. **Para qué**: los algoritmos grandes desperdician ops con listas pequeñas (radix con `2 1 0` = 9 ops) y ordenar 3 es pieza de ordenar 5 (`pb pb` los 2 menores → ordenar 3 → `pa pa`). Pendiente: 2 números y 5 números.

17. (18-09) **O(n) para desorden < 0,2** (propuesta para decidir con el compañero). **Límite teórico**: O(n) no se puede garantizar para *todo* desorden < 0,2. Corto: puede haber hasta 0,1·n² errores; arreglándolos de 1 en 1 (`sa`) → O(n²). Largo (cualquier algoritmo): cada entrada necesita su propia lista (palomar); con k líneas hay 11^k listas; la familia de 5 bloques de n/5 (desordenados solo por dentro, desorden < 0,2) tiene (n/5)!⁵ entradas → mínimo ≈ n log n operaciones (por número: 0,88 con 100, 1,8 con 1000, 2,75 con 10000). Bajar el umbral a otro número fijo no lo arregla. **Algoritmo**: 1) comprobar en O(n) que cada número está como mucho a 1 posición de su sitio (`|índice − posición| ≤ 1`); 2) si se cumple → una vuelta: si los dos de arriba están al revés → `sa`; luego `ra`; n `ra` en total y sin comparar en el último paso (el 8 con el 1). Máx. 2n ops → O(n). Ejemplo `2 1 3 4 6 5 7 8` → 2 `sa` + 8 `ra` = 10. 3) Si no se cumple (p. ej. `3 2 1`) → `--medium` (chunks). **README**: explicar el límite y cuándo se garantiza O(n).

18. (18-09) **Casos pequeños**: **2** → `1 2` nada · `2 1` → `sa`. **3** → decisión 16. **4** → subir el menor por el camino corto → `pb` → ordenar 3 → `pa`. **5** → igual con los 2 menores → ordenar 3 → `pa pa` (ej. `3 0 4 1 2` → `ra pb ra pb pa pa` = 6). **Camino corto** (función única, también para la vuelta de chunks, decisión 13): si la posición está en la primera mitad → `ra`, si no → `rra`. No se busca la jugada perfecta en cada caso: basta la regla.

19. (18-09) **Umbrales**. **Desorden**: 0,2 y 0,5 tal cual dice el subject (bajarlos no arregla el O(n), decisión 17); justificación con mediciones en la Fase 5. **Tamaño**: con **n ≤ 5** se usan los casos pequeños (decisión 18) en **todas** las estrategias, también con flag (el subject pide la lista más corta posible; con n ≤ 5 no cambia la complejidad; se explica en el README). No se sube de 5 porque el método de los casos pequeños con n grande es selección otra vez (O(n²)). Con n > 5 → flag o adaptativa.

20. (18-09) **Reparto, orden y git**. **A = dforteza**, **B = compañera** (dforteza cuida la base, que es lo que más prueba el evaluador; lo más cambiante va a B). El **quicksort se hace juntos** en la Fase 5, no lo hace B sola.
   - **Juntos (primero)**: repo, `push_swap.h` (structs + prototipos), Makefile (`/makefile-42`), libft. Pactar nombres de funciones internas y de las 11 operaciones.
   - **A (entrada y datos)**: flags (6), parseo con `ft_split` + conversión + errores (3-5), liberar y salir con error (15), normalizar (8), desorden (2, 11), `--simple` (12) y `--medium` (13).
   - **B (movimientos y algoritmos)**: funciones internas + 11 operaciones con contadores (10), camino corto + casos pequeños 2-5 (16, 18), `--complex` radix (14) y O(n) (17).
   - **Juntos (final)**: adaptativa, `--bench`, mediciones, quicksort si hay tiempo (Fase 5), README y repaso de defensa.
   - **Orden**: B hace primero las operaciones (1-2 días); mientras, A hace parseo, flags, errores, normalizar y desorden (no usan operaciones). Con los prototipos pactados en el `.h`, A puede escribir algoritmos antes de que las operaciones estén en `main`.
   - **Git**: `main` solo recibe merges revisados; una rama por tarea (`feat/parse`, `feat/ops`, `feat/radix`…); el otro revisa y el autor le explica el código antes del merge; commits en Conventional Commits.
   - **Calendario**: el de la tabla de arriba (columnas Juntos / A / B).

Abiertas: ninguna. Diseño cerrado → Fase 3 (Base).

---

## Diario

Plantilla (copiar arriba del todo cada día):

```
### dd-mm-2026 · Fase: _____ · Horas: _
- Hecho:
- Bloqueos / dudas:
- Mañana:
- ¿Voy en plazo?: sí / no → ajuste:
```

### 18-09-2026 (tarde) · Fase: Base · Horas: _
- Hecho: repo `dforteza/push_swap` creado y clonado; `.gitignore` (plantilla C + push_swap, checker_linux, PDF); borrados `prueba*`, `checker_Mac`, `fedora_checker`. libft copiada (`CC = cc`). Makefile (libft primero con regla `$(LIBFT)`, `-I. -Ilibft`, sin relink, comprobado). `push_swap.h`: `t_node` (value, index, next), `t_ps` (a, b, strategy, bench, count[N_OPS]), `#define` de estrategias y de las 11 operaciones, prototipos de las 11 operaciones (`t_ps *ps`) y de las 4 internas (`t_node **stack`, `push(src, dest)`). Reparto de ficheros en `src/` (A: main, flags, parse, error, normalize, disorder, simple, medium · B: moves, ops_swap_push, ops_rotate, ops_reverse, small_sort, radix, linear · Juntos: adaptive, bench). `main` mínimo compila. Rama `feat/flags`: diseño de flags (devuelve el índice del primer número; comparar `ft_strlen(flag) + 1`; `NONE = -1`; error → `-1` y `main` escribe `Error`) y esqueleto de `flags.c` con 4 funciones descritas.
- Conceptos aclarados: `-I` (buscar `.h`) frente a `-L`/`-l` (enlazar `.a`); incluir (prototipos) frente a enlazar (código); por qué `t_node **` en las internas; `cc` exigido por el subject.
- Bloqueos / dudas: espacios en vez de tabuladores (norminette) → `c_formatter_42` o configurar el editor. `main.c`: línea vacía en la función y falta salto al final.
- Mañana (sáb 19, colchón): programar y probar `flags.c` con los 6 casos, iniciar `ps` en `main` (`ft_bzero` + `strategy = NONE`), luego parseo.
- ¿Voy en plazo?: sí → la base conjunta quedó cerrada hoy; se usa el sáb 19 para adelantar A.

### 18-09-2026 (mañana) · Fase: Diseño · Horas: _
- Hecho: O(n) cerrado (decisión 17): conteo de errores, cota 0,1·n², argumento del palomar (11^k listas, familia de 5 bloques) → O(n) no garantizable para todo desorden < 0,2; algoritmo de una vuelta `sa`/`ra` con comprobación previa y fallback a chunks. Casos pequeños 2, 4 y 5 (decisión 18). Umbrales (decisión 19). Reparto y git (decisión 20): yo A, compañera B, quicksort juntos.
- Bloqueos / dudas:
- Mañana:
- ¿Voy en plazo?:

### 17-09-2026 · Fase: Análisis + Diseño · Horas: _
- Hecho: Fase 1 completa (requisitos, errores, rendimiento, restricciones). Diseño: decisiones 4-14 (argumentos, flags, lista simple, nodo valor+índice, normalizar, flujo, struct principal, operaciones y contadores, desorden en %, selección, chunks, radix + quicksort como mejora). Repaso de complejidad (O/Ω/Θ, reglas, n, log n, n√n). Apuntes en el cuaderno. Simulador de cubitos.
- Bloqueos / dudas: algoritmo O(n) para desorden < 0,2 (difícil de justificar: con desorden 0,2 aún puede haber muchos errores).
- Mañana: O(n), casos pequeños (2 y 5), umbrales, reparto y git (con el compañero). Memoria cerrada (decisión 15); ordenar 3 hecho (decisión 16).
- ¿Voy en plazo?: no del todo → ajuste: el diseño se termina el vie 18 con el compañero (O(n), casos 2 y 5, umbrales, reparto y git) antes de empezar la Base; si hace falta, se usa el colchón del sáb 19.

### 16-09-2026 · Fase: Análisis · Horas: _
- Hecho: subject leído entero en 4 trozos. Plan creado.
- Conceptos aclarados: índice de desorden (parejas, no números pares; ejemplo `[2, 1, 3, 4]` → 0,17); trampas de división entre cero y división entera; adaptativa = selector, no quinto algoritmo (4 algoritmos: O(n²), O(n√n), O(n log n) y O(n)); stdout frente a stderr y redirecciones (`>`, `2>`, `|`); casos de error; checker y cómo se encadena con push_swap.
- Bloqueos / dudas: regla de flags con `--bench`.
- Mañana: análisis y diseño completos antes de empezar con el compañero el viernes.
- ¿Voy en plazo?: sí.
