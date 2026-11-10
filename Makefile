name: Build_Pou_PS3_PKG
on:
  push:
    branches: [main]
  workflow_dispatch:
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - name: Instalar
        run: |
          sudo apt-get update
          sudo apt-get install -y python3 python3-pip p7zip-full
          pip3 install Pillow
      - name: Gerar_Capa
        run: |
          python3 -c "from PIL import Image,ImageDraw;img=Image.new('RGB',(320,176),(135,206,235));d=ImageDraw.Draw(img);d.ellipse([110,30,210,130],fill=(198,142,95),outline=(0,0,0));d.ellipse([130,65,150,95],fill=(255,255,255));d.ellipse([170,65,190,95],fill=(255,255,255));d.text((110,145),'POU_PS3_BR',fill=(0,0,0));img.save('ICON0.PNG')"
          ls -lh ICON0.PNG
      - name: Gerar_PKG
        run: |
          python3 build_pkg.py
          ls -lh *.pkg *.zip
      - name: Upload_PKG
        uses: actions/upload-artifact@v4
        with:
          name: pou-ps3-pkg
          path: POUBR001.pkg