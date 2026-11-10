import os, shutil, struct
TITLE_ID = "POUBR001"
print("BUILD POU PS3 JOGO REAL")
if os.path.exists("pkg_build"):
    shutil.rmtree("pkg_build")
os.makedirs(f"pkg_build/{TITLE_ID}/USRDIR", exist_ok=True)
# Usa o EBOOT de verdade que o make criou
if os.path.exists("EBOOT.BIN"):
    shutil.copy("EBOOT.BIN", f"pkg_build/{TITLE_ID}/USRDIR/EBOOT.BIN")
    print("EBOOT REAL copiado - jogo de verdade!")
else:
    print("ERRO: EBOOT.BIN nao encontrado!")
    raise SystemExit(1)
with open(f"pkg_build/{TITLE_ID}/PARAM.SFO", "wb") as f:
    f.write(b"\x00PSF\x01\x01\x00\x00")
    f.write(struct.pack("<III", 0x100, 0x100, 0x100))
    f.write(b"POU_PS3_BR")
if os.path.exists("ICON0.PNG"):
    shutil.copy("ICON0.PNG", f"pkg_build/{TITLE_ID}/ICON0.PNG")
    print("Capa copiada")
shutil.make_archive("POUBR001", "zip", "pkg_build", TITLE_ID)
shutil.move("POUBR001.zip", "POUBR001.pkg")
print("POUBR001.pkg criado!")