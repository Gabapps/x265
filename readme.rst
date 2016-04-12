=================
x265 HEVC Encoder
=================

| **Read:** | Online `documentation <http://x265.readthedocs.org/en/default/>`_ | Developer `wiki <http://bitbucket.org/multicoreware/x265/wiki/>`_
| **Download:** | `releases <http://ftp.videolan.org/pub/videolan/x265/>`_ 
| **Interact:** | #x265 on freenode.irc.net | `x265-devel@videolan.org <http://mailman.videolan.org/listinfo/x265-devel>`_ | `Report an issue <https://bitbucket.org/multicoreware/x265/issues?status=new&status=open>`_

`x265 <https://www.videolan.org/developers/x265.html>`_ is an open
source HEVC encoder. See the developer wiki for instructions for
downloading and building the source.

x265 is free to use under the `GNU GPL <http://www.gnu.org/licenses/gpl-2.0.html>`_ 
and is also available under a commercial `license <http://x265.org>`_ 

HEVC compression complexity estimation in full-intra
====================================================

This is a fork of the x265 HEVC encoder uses with the papilib profiling library
in order to build an estimation model of the full-intra complexity. This is a
research project realized throughout my engineering studies at INSA Rennes.

IDE
---

When debugging is needed, an IDE is really useful. I added in the build folder a
configuration for eclipse CDT4 in debugging. The project can be generated using the
provided bash file.

Profiling tools
---------------

I am using different tools to profile x265 :
* To acquire processor times : `papilib <http://icl.cs.utk.edu/papi/>`_
* To analyse profiling data : `numpy <http://www.numpy.org/>`_ and `matplotlib<http://matplotlib.org/>`_

x265 configuration
------------------

* No wavefront : ``--no-wpp``
* Full-intra : ``-I 1``
* Presets : ``-p <preset-number[0-9]>``

Call hierarchies for full-intra encoding
--------------------------------------

* ``FrameEncoder::compressFrame``
   * ``FrameEncoder::processRowEncoder``
      * ``Analysis::compressCTU`` : Compress an entire CTU
         * ``Analysis::compressIntraCU`` : Find best encoding mode before encoding (RDO)

For the moment, most of the profiling job is done in ``Analysis::compressIntraCU`` (source/encoder/analysis.cpp)


