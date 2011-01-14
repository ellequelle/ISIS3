
#ifndef VoyagerCamera_h
#define VoyagerCamera_h
/**                                                                       
 * @file                                                                  
 * $Revision: 1.0 $ 
 * $Date: 2009/05/27 12:08:01 $ 
 *                                                                        
 *   Unless noted otherwise, the portions of Isis written by the USGS are public
 *   domain. See individual third-party library and package descriptions for 
 *   intellectual property information,user agreements, and related information.
 *                                                                        
 *   Although Isis has been used by the USGS, no warranty, expressed or implied,
 *   is made by the USGS as to the accuracy and functioning of such software 
 *   and related material nor shall the fact of distribution constitute any such 
 *   warranty, and no responsibility is assumed by the USGS in connection 
 *   therewith.                                                           
 *                                                                        
 *   For additional information, launch                                   
 *   $ISISROOT/doc//documents/Disclaimers/Disclaimers.html in a browser or see 
 *   the Privacy &amp; Disclaimers page on the Isis website,              
 *   http://isis.astrogeology.usgs.gov, and the USGS privacy and disclaimers on
 *   http://www.usgs.gov/privacy.html.                                    
 */                                                                       

#include "FramingCamera.h"

namespace Isis {
  /**                                                                       
   * @brief Voyager Camera Model                
   *                                        
   * This is the camera class for Voyager 1 and 2 wide and narrow 
   * angle cameras. 
   * 
   * @ingroup SpiceInstrumentsAndCameras                                   
   * @ingroup Voyager
   *                                                                        
   * @author 2010-07-19 Mackenzie Boyd
   * 
   * @internal 
   *   @history 2010-07-19 Mackenzie Boyd - Original Version 
   */                                                                       
  class VoyagerCamera : public Isis::FramingCamera {
    public:
      VoyagerCamera (Isis::Pvl &lab);
      ~VoyagerCamera () {};      

      /** 
       * CK frame ID -
       * Voyager 1 instrument code (VG1_SCAN_PLATFORM) = -31100
       * Voyager 2 instrument code (VG1_SCAN_PLATFORM) [sic] = -32100
       */
      virtual int CkFrameId() const { return p_ckFrameId; }

      /** CK Reference ID - B1950 */
      virtual int CkReferenceId() const { return (2); }

      /** 
       * SPK Target Body ID -
       * VOYAGER 1 = -31
       * VOYAGER 2 = -32
       */
      virtual int SpkTargetId() const { return p_spkTargetId; }

      /** SPK Reference ID - J2000 */
      virtual int SpkReferenceId() const { return (1); }

    private:
      int p_ckFrameId;
      int p_spkTargetId;
  };
};
#endif

