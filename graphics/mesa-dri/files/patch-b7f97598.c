commit b7f975980916d670dcfc280af1678f4439a59d2f
Author: Timur Kristóf <timur.kristof@gmail.com>
Date:   Tue Jan 21 16:04:33 2020 +0100

    radeon: Move si_get_pic_param to radeon_vce.c
    
    Signed-off-by: Timur Kristóf <timur.kristof@gmail.com>
    Reviewed-by: Marek Olšák <marek.olsak@amd.com>
    Part-of: <https://gitlab.freedesktop.org/mesa/mesa/merge_requests/3488>

diff --git src/gallium/drivers/radeon/radeon_vce.c src/gallium/drivers/radeon/radeon_vce.c
index 84d3c1e2fa4..652b4250654 100644
--- src/gallium/drivers/radeon/radeon_vce.c
+++ src/gallium/drivers/radeon/radeon_vce.c
@@ -48,6 +48,10 @@
 #define FW_52_8_3 ((52 << 24) | (8 << 16) | (3 << 8))
 #define FW_53 (53 << 24)
 
+/* version specific function for getting parameters */
+static void (*si_get_pic_param)(struct rvce_encoder *enc,
+                                struct pipe_h264_enc_picture_desc *pic) = NULL;
+
 /**
  * flush commands to the hardware
  */
diff --git src/gallium/drivers/radeon/radeon_vce.h src/gallium/drivers/radeon/radeon_vce.h
index cf625e6fed7..b5cfe178061 100644
--- src/gallium/drivers/radeon/radeon_vce.h
+++ src/gallium/drivers/radeon/radeon_vce.h
@@ -437,10 +437,6 @@ void si_vce_50_init(struct rvce_encoder *enc);
 /* init vce fw 52 specific callbacks */
 void si_vce_52_init(struct rvce_encoder *enc);
 
-/* version specific function for getting parameters */
-void (*si_get_pic_param)(struct rvce_encoder *enc,
-                      struct pipe_h264_enc_picture_desc *pic);
-
 /* get parameters for vce 40.2.2 */
 void si_vce_40_2_2_get_param(struct rvce_encoder *enc,
 			     struct pipe_h264_enc_picture_desc *pic);
