#define BinNodePosi(T) BinNode<T>*	// 节点位置
#define stature(p) ((p) ? (p)->height : -1)
template<typename T> struct BinNode {
	BinNodePosi(T) parent, lChild, rChild; // 父亲、孩子
	T data;		//数据
	int height;	// 高度
	int size(); //规模
	BinNode():parent(NULL),lChild(NULL),rChild(NULL),height(0),size(1),data(NULL){}
	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
			int h = 0, int s = 1):
		data(e),parent(p),lChild(lc),rChild(rc),height(h),size(s) {}
	BinNodePosi(T) insertAsLC(T const &);	// 作为左孩子插入新节点
	BinNodePosi(T) insertAsRC(T const &);	// 作为右孩子插入新节点
	BinNodePosi(T) succ();	// 中序遍历下，当前节点的直接后继
	int updateHeight(BinNodePosi(T) x);
	void updateHeightAbove(BinNodePosi(T) x);
	template<typename VST> void travLevel(VST &);	//  子树层次遍历
	template<typename VST> void travPre(VST &);		// 子树先序遍历
	template<typename VST> void travIn(VST &);		// 子树中序遍历
	template<typename VST> void tranPost(VST &);	// 子树后序遍历
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
