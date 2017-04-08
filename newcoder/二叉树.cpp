#define BinNodePosi(T) BinNode<T>*	// �ڵ�λ��
#define stature(p) ((p) ? (p)->height : -1)
template<typename T> struct BinNode {
	BinNodePosi(T) parent, lChild, rChild; // ���ס�����
	T data;		//����
	int height;	// �߶�
	int size(); //��ģ
	BinNode():parent(NULL),lChild(NULL),rChild(NULL),height(0),size(1),data(NULL){}
	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
			int h = 0, int s = 1):
		data(e),parent(p),lChild(lc),rChild(rc),height(h),size(s) {}
	BinNodePosi(T) insertAsLC(T const &);	// ��Ϊ���Ӳ����½ڵ�
	BinNodePosi(T) insertAsRC(T const &);	// ��Ϊ�Һ��Ӳ����½ڵ�
	BinNodePosi(T) succ();	// ��������£���ǰ�ڵ��ֱ�Ӻ��
	int updateHeight(BinNodePosi(T) x);
	void updateHeightAbove(BinNodePosi(T) x);
	template<typename VST> void travLevel(VST &);	//  ������α���
	template<typename VST> void travPre(VST &);		// �����������
	template<typename VST> void travIn(VST &);		// �����������
	template<typename VST> void tranPost(VST &);	// �����������
};
template<typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T &e) {
	return lChild = new BinNode(e,this);
}
template<typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T &e) {
	return rChild = new BinNode(e, this);
}
template<typename T> BinNodePosi(T) BinNode<T>::size() {
	int s = 1;
	if (lChild) { s += lChild->size(); }
	if (rChild) { s += rChild->size(); }
	return s;
}

template<typename T> int BinNode<T>::updateHeight(BinNodePosi(T) x) {
	return x->height = 1 + max(stature(x->lChild), stature(x->rChild));
}
template<typename T> void BinNode<T>::updateHeightAbove(BinNodePosi(T) x) {
	while (x) {
		updateHeight(x);
		x = x->parent;
	}
}
