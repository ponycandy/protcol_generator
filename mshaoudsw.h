#ifndef MSHAOUDSW_H
#define MSHAOUDSW_H
void makedata(test ptopic, QByteArray &sending_data){
const char* ptData = pre_assigned_char
int offset,size;size=0;
offset=4;memcpy((void *)(ptData), (void *)&ptopic.op1, offset);ptData += offset;size+=offset;
offset=4;memcpy((void *)(ptData), (void *)&ptopic.op2, offset);ptData += offset;size+=offset;
sending_data.setRawData(pre_assigned_char,size);
}

#endif // MSHAOUDSW_H
