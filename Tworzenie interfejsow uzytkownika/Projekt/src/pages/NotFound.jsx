import { Link } from 'react-router-dom';
import { motion } from 'framer-motion';

export default function NotFound() {
    return (
        <motion.div
            className="flex flex-col items-center justify-center min-h-screen px-6 text-center bg-gray-50 dark:bg-gray-900 text-gray-900 dark:text-gray-100"
            initial={{ opacity: 0, y: 10 }}
            animate={{ opacity: 1, y: 0 }}
            exit={{ opacity: 0, y: -10 }}
            transition={{ duration: 0.4 }}
        >
            <motion.h1
                className="text-6xl font-extrabold text-blue-600 animate-pulse mb-4"
                initial={{ opacity: 0, scale: 0.8 }}
                animate={{ opacity: 1, scale: 1 }}
                transition={{ delay: 0.2, type: 'spring', stiffness: 200 }}
            >
                404
            </motion.h1>

            <motion.h2
                className="text-2xl font-semibold mb-2"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.4 }}
            >
                Strona nie została znaleziona
            </motion.h2>

            <motion.p
                className="text-gray-600 dark:text-gray-300 mb-6 max-w-md"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.6 }}
            >
                Wygląda na to, że adres jest nieprawidłowy lub strona została usunięta.
                Sprawdź adres lub wróć na stronę główną.
            </motion.p>

            <motion.div
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.8 }}
            >
                <Link
                    to="/"
                    className="bg-blue-600 hover:bg-blue-700 text-white px-6 py-3 rounded-lg shadow transition"
                >
                    Wróć na stronę główną
                </Link>
            </motion.div>
        </motion.div>
    );
}
