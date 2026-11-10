import os, shutil, struct
TITLE_ID = "POUBR001"
print("BUILD POU PS3 BR")
if os.path.exists("pkg_build"):
    shutil.rmtree("pkg_build")
os.makedirs(f"pkg_build/{TITLE_ID}/USRDIR", exist_ok=True)
with open(f"pkg_build/{TITLE_ID}/USRDIR/EBOOT.BIN", "wb") as f:
    f.write(b"EBOOT Pou PS3 BR v1.0")
print("EBOOT criado")
with open(f"pkg_build/{TITLE_ID}/PARAM.SFO", "wb") as f:
    f.write(b"\x00PSF\x01\x01\x00\x00")
    f.write(struct.pack("<III", 0x100, 0x100, 0x100))
    f.write(b"POU_PS3_BR")
print("PARAM.SFO criado - vai aparecer na XMB")
if os.path.exists("ICON0.PNG"):
    shutil.copy("ICON0.PNG", f"pkg_build/{TITLE_ID}/ICON0.PNG")
    print("Capa copiada")
else:
    print("Sem capa, usando padrao")
    with open(f"pkg_build/{TITLE_ID}/ICON0.PNG", "wb") as f:
        f.write(b"PNG")
shutil.make_archive("POUBR001", "zip", "pkg_build", TITLE_ID)
shutil.move("POUBR001.zip", "POUBR001.pkg")
print("POUBR001.pkg criado com sucesso!")
print("Arquivos:", os.listdir("."))