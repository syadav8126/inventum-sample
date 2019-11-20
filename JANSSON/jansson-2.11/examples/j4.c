#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include <string.h>

void print_json(json_t *root);
void print_json_aux(json_t *element, int indent);
void print_json_indent(int indent);
const char *json_plural(int count);
void print_json_object(json_t *element, int indent);
void print_json_array(json_t *element, int indent);
void print_json_string(json_t *element, int indent);
void print_json_integer(json_t *element, int indent);
void print_json_real(json_t *element, int indent);
void print_json_true(json_t *element, int indent);
void print_json_false(json_t *element, int indent);
void print_json_null(json_t *element, int indent);

void print_json(json_t *root) {
    print_json_aux(root, 0);
}

void print_json_aux(json_t *element, int indent) {
    switch (json_typeof(element)) {
    case JSON_OBJECT:
        print_json_object(element, indent);
        break;
    case JSON_ARRAY:
        print_json_array(element, indent);
        break;
    case JSON_STRING:
        print_json_string(element, indent);
        break;
    case JSON_INTEGER:
        print_json_integer(element, indent);
        break;
    case JSON_REAL:
        print_json_real(element, indent);
        break;
    case JSON_TRUE:
        print_json_true(element, indent);
        break;
    case JSON_FALSE:
        print_json_false(element, indent);
        break;
    case JSON_NULL:
        print_json_null(element, indent);
        break;
    default:
        fprintf(stderr, "unrecognized JSON type %d\n", json_typeof(element));
    }
}

void print_json_indent(int indent) {
    int i;
    for (i = 0; i < indent; i++) { putchar(' '); }
}

const char *json_plural(int count) {
    return count == 1 ? "" : "s";
}

void print_json_object(json_t *element, int indent) {
    size_t size;
    const char *key;
    json_t *value;

    print_json_indent(indent);
    size = json_object_size(element);
    json_object_foreach(element, key, value) {
//      print_json_indent(indent + 2);
        printf("{\"%s\" :", key);
        print_json_aux(value, indent + 2);
    }

}

void print_json_array(json_t *element, int indent) {
    size_t i;
    size_t size = json_array_size(element);
//    print_json_indent(indent);
    for (i = 0; i < size; i++) {
        print_json_aux(json_array_get(element, i), indent + 2);
    }
}

void print_json_string(json_t *element, int indent) {
//    print_json_indent(indent);
    printf(" %s}", json_string_value(element));
}

void print_json_integer(json_t *element, int indent) {
//    print_json_indent(indent);
    printf("%" JSON_INTEGER_FORMAT "},", json_integer_value(element));
}

void print_json_real(json_t *element, int indent) {
    print_json_indent(indent);
    printf("%f\n", json_real_value(element));
}

void print_json_true(json_t *element, int indent) {
    (void)element;
    print_json_indent(indent);
    printf("JSON True");
}

void print_json_false(json_t *element, int indent) {
    (void)element;
    print_json_indent(indent);
    printf("JSON False");
}

void print_json_null(json_t *element, int indent) {
    (void)element;
    print_json_indent(indent);
  printf("JSON Null");
}

int main(){
	FILE *fp;
	fp = fopen("/etc/protocols","r");
	fseek(fp, 302, SEEK_CUR);
	char *p, buff[250], dtm[250],protocol[20], ignore[100], ignore1[100];
	int index;
	json_t * object = json_object();
	const char *key = "obj";
	json_t * array = json_array();
//	json_t * value = array;
	json_object_set(object,key,array);


	p = fgets(buff, 50, fp);
	while(p!='\0'){	
	json_t * object1 = json_object();
        json_t * object2 = json_object();
	p = fgets(buff, 50, fp);
	strcpy(dtm,buff);
	sscanf(dtm, "%s %d %s %s", protocol, &index, ignore, ignore1 );
	const char *key1 = "Protocol";
	json_t * value1 = json_string(protocol);
	const char *key2 = "index";
	json_t * value2 = json_integer(index);	
	
//	json_object_foreach(object1, key1, value1){
	json_object_set_new(object1, key1, value1);
//	}
//	json_object_foreach(object2, key2, value2){
	json_object_set_new(object2, key2, value2);
//	}
	json_array_append(array,object1);
	json_array_append(array,object2);
 
	 }
	
	json_dump_file(array, "/home/saurabh/make1", 0644);
	print_json(object);
	json_decref(array);
	json_decref(object);
	return 0;
}










                                  
