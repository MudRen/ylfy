// clean_up.c
// by Annihilator@ES2

int clean_up()
{
    object *inv;
    int i;

    if ( !clonep() && this_object()->query("no_clean_up") ) return 1; // �Ǹ��Ƶģ����в��� no_clean_up
    if ( interactive(this_object()) ) return 1; // �ɻ�����
    // If we are contained in something, let environment do the clean
    // up instead of making recursive call. This will prevent clean-up
    // time lag.
    if ( environment() ) return 1; // �л�����
    inv = all_inventory();
    for ( i = sizeof(inv) - 1; i >= 0; i-- )
	{
        if ( interactive(inv[i]) ) return 1; // �ڰ����пɻ�����
	}
    destruct(this_object());
    return 0;
}
