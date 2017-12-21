;; variables
(declare-var alu_b15 Bool)
(declare-var alu_b20 Bool)
(declare-var alu_b25 Bool)
(declare-var alu_b30 Bool)
(declare-var alu_b35 Bool)
(declare-var alu_b40 Bool)
(declare-var alu_b45 Bool)
(declare-var alu_b51 Bool)
(declare-var alu_b56 Bool)
(declare-var alu_b61 Bool)
(declare-var alu_b66 Bool)
(declare-var alu_b7 Bool)
(declare-var alu_b71 Bool)
(declare-var alu_b76 Bool)
(declare-var alu_b81 Bool)
(declare-var alu_b86 Bool)
(declare-var alu_bv11 Int)
(declare-var alu_bv14 Int)
(declare-var alu_bv16 Int)
(declare-var alu_bv18 Int)
(declare-var alu_bv19 Int)
(declare-var alu_bv2 Int)
(declare-var alu_bv21 Int)
(declare-var alu_bv23 Int)
(declare-var alu_bv24 Int)
(declare-var alu_bv26 Int)
(declare-var alu_bv28 Int)
(declare-var alu_bv29 Int)
(declare-var alu_bv31 Int)
(declare-var alu_bv33 Int)
(declare-var alu_bv34 Int)
(declare-var alu_bv36 Int)
(declare-var alu_bv38 Int)
(declare-var alu_bv39 Int)
(declare-var alu_bv41 Int)
(declare-var alu_bv43 Int)
(declare-var alu_bv44 Int)
(declare-var alu_bv46 Int)
(declare-var alu_bv48 Int)
(declare-var alu_bv50 Int)
(declare-var alu_bv52 Int)
(declare-var alu_bv54 Int)
(declare-var alu_bv55 Int)
(declare-var alu_bv57 Int)
(declare-var alu_bv59 Int)
(declare-var alu_bv6 Int)
(declare-var alu_bv60 Int)
(declare-var alu_bv62 Int)
(declare-var alu_bv64 Int)
(declare-var alu_bv65 Int)
(declare-var alu_bv67 Int)
(declare-var alu_bv69 Int)
(declare-var alu_bv70 Int)
(declare-var alu_bv72 Int)
(declare-var alu_bv74 Int)
(declare-var alu_bv75 Int)
(declare-var alu_bv77 Int)
(declare-var alu_bv79 Int)
(declare-var alu_bv8 Int)
(declare-var alu_bv80 Int)
(declare-var alu_bv82 Int)
(declare-var alu_bv84 Int)
(declare-var alu_bv85 Int)
(declare-var alu_bv87 Int)
(declare-var alu_bv89 Int)
(declare-var pc Int)
(declare-var pc_0 Int)
(declare-var pc_1 Int)
(declare-var r0 Int)
(declare-var r0_0 Int)
(declare-var r0_1 Int)
(declare-var r1 Int)
(declare-var r1_0 Int)
(declare-var r1_1 Int)
(declare-var rom (Array Int Int))
(declare-var rom_0 (Array Int Int))
(declare-var rom_1 (Array Int Int))
;; relations
(declare-rel alu_instr.decode (Bool))
(declare-rel alu_instr.pc (Int Int))
(declare-rel alu_instr.r0 (Int Int Int (Array Int Int) Int))
(declare-rel alu_instr.r1 (Int Int Int (Array Int Int) Int))
(declare-rel alu_instr.rom ((Array Int Int) (Array Int Int)))
(declare-rel alu_child.decode (Bool))
(declare-rel alu_child.pc (Int Int))
(declare-rel alu_child.r0 (Int Int Int (Array Int Int) Int))
(declare-rel alu_child.r1 (Int Int Int (Array Int Int) Int))
(declare-rel alu_child.rom ((Array Int Int) (Array Int Int)))
(declare-rel L_alu (Int Int Int (Array Int Int) Int Int (Array Int Int) Int))
(declare-rel alu_instr (Int Int Int (Array Int Int) Int Int (Array Int Int) Int))
;; clauses
(rule (alu_instr.decode true))
(rule (=> (= alu_bv2 (+ pc 1))
          (alu_instr.pc pc alu_bv2)))
(rule (=> (and (= alu_b15 (= alu_bv16 12))
               (= alu_b20 (= alu_bv21 10))
               (= alu_b25 (= alu_bv26 8))
               (= alu_b30 (= alu_bv31 6))
               (= alu_b35 (= alu_bv36 4))
               (= alu_b40 (= alu_bv41 2))
               (= alu_b45 (= alu_bv46 0))
               (= alu_b7 (= alu_bv8 14))
               (= alu_bv11 (bv2int (bvor ((_ int2bv 4) r0) ((_ int2bv 4) r1))))
               (= alu_bv14 (ite alu_b15 alu_bv18 alu_bv19))
               (= alu_bv16 (select rom pc))
               (= alu_bv18 (- 0 r0))
               (= alu_bv19 (ite alu_b20 alu_bv23 alu_bv24))
               (= alu_bv21 (select rom pc))
               (= alu_bv23 (bv2int (bvand ((_ int2bv 4) r0) ((_ int2bv 4) r1))))
               (= alu_bv24 (ite alu_b25 alu_bv28 alu_bv29))
               (= alu_bv26 (select rom pc))
               (= alu_bv28 (bv2int (bvnot ((_ int2bv 4) r0))))
               (= alu_bv29 (ite alu_b30 alu_bv33 alu_bv34))
               (= alu_bv31 (select rom pc))
               (= alu_bv33 (- r0 r1))
               (= alu_bv34 (ite alu_b35 alu_bv38 alu_bv39))
               (= alu_bv36 (select rom pc))
               (= alu_bv38 (- r0 r0))
               (= alu_bv39 (ite alu_b40 alu_bv43 alu_bv44))
               (= alu_bv41 (select rom pc))
               (= alu_bv43 (+ r0 r1))
               (= alu_bv44 (ite alu_b45 alu_bv48 r0))
               (= alu_bv46 (select rom pc))
               (= alu_bv48 (+ r0 r0))
               (= alu_bv6 (ite alu_b7 alu_bv11 alu_bv14))
               (= alu_bv8 (select rom pc)))
          (alu_instr.r0 pc r0 r1 rom alu_bv6)))
(rule (=> (and (= alu_b51 (= alu_bv52 15))
               (= alu_b56 (= alu_bv57 13))
               (= alu_b61 (= alu_bv62 11))
               (= alu_b66 (= alu_bv67 9))
               (= alu_b71 (= alu_bv72 7))
               (= alu_b76 (= alu_bv77 5))
               (= alu_b81 (= alu_bv82 3))
               (= alu_b86 (= alu_bv87 1))
               (= alu_bv50 (ite alu_b51 alu_bv54 alu_bv55))
               (= alu_bv52 (select rom pc))
               (= alu_bv54 (- 0 r1))
               (= alu_bv55 (ite alu_b56 alu_bv59 alu_bv60))
               (= alu_bv57 (select rom pc))
               (= alu_bv59 (bv2int (bvor ((_ int2bv 4) r1) ((_ int2bv 4) r0))))
               (= alu_bv60 (ite alu_b61 alu_bv64 alu_bv65))
               (= alu_bv62 (select rom pc))
               (= alu_bv64 (bv2int (bvnot ((_ int2bv 4) r1))))
               (= alu_bv65 (ite alu_b66 alu_bv69 alu_bv70))
               (= alu_bv67 (select rom pc))
               (= alu_bv69 (bv2int (bvand ((_ int2bv 4) r1) ((_ int2bv 4) r0))))
               (= alu_bv70 (ite alu_b71 alu_bv74 alu_bv75))
               (= alu_bv72 (select rom pc))
               (= alu_bv74 (- r0 r0))
               (= alu_bv75 (ite alu_b76 alu_bv79 alu_bv80))
               (= alu_bv77 (select rom pc))
               (= alu_bv79 (- r1 r0))
               (= alu_bv80 (ite alu_b81 alu_bv84 alu_bv85))
               (= alu_bv82 (select rom pc))
               (= alu_bv84 (+ r1 r1))
               (= alu_bv85 (ite alu_b86 alu_bv89 r1))
               (= alu_bv87 (select rom pc))
               (= alu_bv89 (+ r0 r1)))
          (alu_instr.r1 pc r0 r1 rom alu_bv50)))
(rule (alu_instr.rom rom rom))
(rule (alu_child.decode true))
(rule (=> (= alu_bv2 (+ pc 1))
          (alu_child.pc pc alu_bv2)))
(rule (=> (and (= alu_b15 (= alu_bv16 12))
               (= alu_b20 (= alu_bv21 10))
               (= alu_b25 (= alu_bv26 8))
               (= alu_b30 (= alu_bv31 6))
               (= alu_b35 (= alu_bv36 4))
               (= alu_b40 (= alu_bv41 2))
               (= alu_b45 (= alu_bv46 0))
               (= alu_b7 (= alu_bv8 14))
               (= alu_bv11 (bv2int (bvor ((_ int2bv 4) r0) ((_ int2bv 4) r1))))
               (= alu_bv14 (ite alu_b15 alu_bv18 alu_bv19))
               (= alu_bv16 (select rom pc))
               (= alu_bv18 (- 0 r0))
               (= alu_bv19 (ite alu_b20 alu_bv23 alu_bv24))
               (= alu_bv21 (select rom pc))
               (= alu_bv23 (bv2int (bvand ((_ int2bv 4) r0) ((_ int2bv 4) r1))))
               (= alu_bv24 (ite alu_b25 alu_bv28 alu_bv29))
               (= alu_bv26 (select rom pc))
               (= alu_bv28 (bv2int (bvnot ((_ int2bv 4) r0))))
               (= alu_bv29 (ite alu_b30 alu_bv33 alu_bv34))
               (= alu_bv31 (select rom pc))
               (= alu_bv33 (- r0 r1))
               (= alu_bv34 (ite alu_b35 alu_bv38 alu_bv39))
               (= alu_bv36 (select rom pc))
               (= alu_bv38 (- r0 r0))
               (= alu_bv39 (ite alu_b40 alu_bv43 alu_bv44))
               (= alu_bv41 (select rom pc))
               (= alu_bv43 (+ r0 r1))
               (= alu_bv44 (ite alu_b45 alu_bv48 r0))
               (= alu_bv46 (select rom pc))
               (= alu_bv48 (+ r0 r0))
               (= alu_bv6 (ite alu_b7 alu_bv11 alu_bv14))
               (= alu_bv8 (select rom pc)))
          (alu_child.r0 pc r0 r1 rom alu_bv6)))
(rule (=> (and (= alu_b51 (= alu_bv52 15))
               (= alu_b56 (= alu_bv57 13))
               (= alu_b61 (= alu_bv62 11))
               (= alu_b66 (= alu_bv67 9))
               (= alu_b71 (= alu_bv72 7))
               (= alu_b76 (= alu_bv77 5))
               (= alu_b81 (= alu_bv82 3))
               (= alu_b86 (= alu_bv87 1))
               (= alu_bv50 (ite alu_b51 alu_bv54 alu_bv55))
               (= alu_bv52 (select rom pc))
               (= alu_bv54 (- 0 r1))
               (= alu_bv55 (ite alu_b56 alu_bv59 alu_bv60))
               (= alu_bv57 (select rom pc))
               (= alu_bv59 (bv2int (bvor ((_ int2bv 4) r1) ((_ int2bv 4) r0))))
               (= alu_bv60 (ite alu_b61 alu_bv64 alu_bv65))
               (= alu_bv62 (select rom pc))
               (= alu_bv64 (bv2int (bvnot ((_ int2bv 4) r1))))
               (= alu_bv65 (ite alu_b66 alu_bv69 alu_bv70))
               (= alu_bv67 (select rom pc))
               (= alu_bv69 (bv2int (bvand ((_ int2bv 4) r1) ((_ int2bv 4) r0))))
               (= alu_bv70 (ite alu_b71 alu_bv74 alu_bv75))
               (= alu_bv72 (select rom pc))
               (= alu_bv74 (- r0 r0))
               (= alu_bv75 (ite alu_b76 alu_bv79 alu_bv80))
               (= alu_bv77 (select rom pc))
               (= alu_bv79 (- r1 r0))
               (= alu_bv80 (ite alu_b81 alu_bv84 alu_bv85))
               (= alu_bv82 (select rom pc))
               (= alu_bv84 (+ r1 r1))
               (= alu_bv85 (ite alu_b86 alu_bv89 r1))
               (= alu_bv87 (select rom pc))
               (= alu_bv89 (+ r0 r1)))
          (alu_child.r1 pc r0 r1 rom alu_bv50)))
(rule (alu_child.rom rom rom))
;; wrapping clauses
(rule (=> (and (L_alu pc_0 r0_0 r1_0 rom_0 pc r0 rom r1)
               (alu_child.decode true)
               (alu_child.pc pc alu_bv2)
               (alu_child.r0 pc r0 r1 rom alu_bv6)
               (alu_child.r1 pc r0 r1 rom alu_bv50)
               (alu_child.rom rom rom))
          (L_alu pc_0 r0_0 r1_0 rom_0 alu_bv2 alu_bv6 rom alu_bv50)))
(rule (L_alu pc r0 r1 rom pc r0 rom r1))
(rule (=> (and (= alu_bv2 pc_1)
               (= alu_bv50 r1_1)
               (= alu_bv6 r0_1)
               (= rom rom_1)
               (L_alu pc_0 r0_0 r1_0 rom_0 pc r0 rom r1)
               (alu_instr.decode true)
               (alu_instr.pc pc alu_bv2)
               (alu_instr.r0 pc r0 r1 rom alu_bv6)
               (alu_instr.r1 pc r0 r1 rom alu_bv50)
               (alu_instr.rom rom rom))
          (alu_instr pc_0 r0_0 r1_0 rom_0 pc_1 r0_1 rom_1 r1_1)))
