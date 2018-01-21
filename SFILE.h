template<typename T>
class TSLinkedNode
{
   public:
      TSLinkedNode(){
	    v0 = 0;
	    v1 = 0;  
      }
      virtual ~TSLinkedNode(){
      }
    public:
      int v0;
      int v1;
};

namespace Storm
{
    class SFile
    {
	    public:
	    	signed int RemoveArchiveRef();
	    	signed int RemoveFileRef();
	    public:
        class ArchivePtr：public ARCHIVEREC//栈区变量回收时，解除锁定
        {
	        public:
	        	~ArchivePtr();
        };
        class ArchivePtrLocked：public ArchivePtr
	    {
		    public:
		    	ArchivePtrLocked(int a2);//锁定指定文件
	    };
	    class ARCHIVEREC:public TSLinkedNode<ARCHIVEREC>,public SFile//列表
	    {
		    public:
		    	ARCHIVEREC();
	    };
	    class FilePtr：public FILEREC//栈区变量回收时，解除锁定
	    {
		    public:
		    	~FilePtr();
	    };
	    class FilePtrLocked:public FilePtr
	    {
		    public:
		    	FilePtrLocked(int a2);
	    };
	    class FILEREC:public TSLinkedNode<FILEREC>,public SFile//列表
	    {
		    public:
		    	FILEREC();
	    };
    };















	
}
